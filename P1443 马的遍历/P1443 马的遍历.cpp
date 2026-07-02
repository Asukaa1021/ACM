#include<bits/stdc++.h>
using namespace std;
int n,m,stx,sty;
bool vis[405][405];
int ans[405][405];
int gx[8]={1,1,-1,-1,2,2,-2,-2};
int gy[8]={2,-2,2,-2,1,-1,1,-1};
queue<pair<int,int>> q;

int main()
{
	cin>>n>>m>>stx>>sty;
	memset(ans,-1,sizeof ans);
	vis[stx][sty] = true;
	ans[stx][sty] = 0;
	q.push(make_pair(stx,sty));
	while(!q.empty())
	{
		for(int i=0;i<8;i++)
		{
			int xx = q.front().first + gx[i];
			int yy = q.front().second + gy[i];
			if(vis[xx][yy] == false && xx>=1 && xx <= n && yy >=1 && yy <=m)
			{	
				q.push(make_pair(xx,yy));
				ans[xx][yy] = ans[q.front().first][q.front().second] + 1;
				vis[xx][yy] = true;
			}
		}
		q.pop();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
		
}