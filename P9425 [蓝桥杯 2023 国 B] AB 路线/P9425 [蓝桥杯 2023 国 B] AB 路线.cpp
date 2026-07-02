#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans = LONG_MAX;
char Map[1005][1005];
bool vis[1005][1005][11];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
struct node
{
	int x,y,depth;
	int c;
	long long cnt;
};
queue<node> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			cin >> Map[i][j];

	q.push({1,1,1,0,0});
	vis[1][1][1] = 1;
	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int depth = q.front().depth;
		int c = q.front().c;
		long long cnt = q.front().cnt;
		q.pop();
		char tag;
		tag = 'A' + c;
		if(x == n && y == m && tag == Map[x][y])
		{
			ans = min(ans,cnt);
			continue;
		}
		if(depth == k)
		{
			depth = 0;
			c = 1 - c;
			tag = 'A' + c;
		}
		
		for(int i = 0;i < 4;i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx < 1 || xx > n || yy < 1 || yy > m || Map[xx][yy] != tag) continue;
			if(vis[xx][yy][depth + 1]) continue;
			vis[xx][yy][depth + 1] = true;
			q.push({xx,yy,depth + 1,c,cnt + 1});
		}
		//cout << x << ' ' << y << " -> ";
	}
	if(ans == LONG_MAX) puts("-1");
	else cout << ans << endl;
}