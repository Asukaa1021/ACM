#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int vis[7][7];
int sx,sy,ex,ey; 
long long ans;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void dfs(int fx , int fy)
{
	if(fx == ex && fy == ey)
	{
		ans++;
		return;
	} 
	for(int i=0;i<=3;i++)
	{
		int x = fx + dx[i];
		int y = fy + dy[i];
		if(x >= 1 && x <= n && y >= 1 && y <= m && vis[x][y] == 0)
		{
			vis[x][y] = 1;
			dfs(x,y);
			vis[x][y] = 0;
		}
	}
}

int main() 
{
	cin>> n >> m >> t;
	cin>> sx >> sy >> ex >> ey;
	for(int i=1;i<=t;i++) 
	{
		int x,y;
		cin>> x >> y;
		vis[x][y] = -1;
	}
	if(vis[ex][ey] == -1)
	{
		cout << 0 << endl;
		return 0;
	}
	if(ex == sx && ey == sy)
	{
		cout<< 1 <<endl;
	}
	vis[sx][sy] = 1;
	dfs(sx,sy);
	cout << ans << endl;
}