#include<bits/stdc++.h>
using namespace std;
int n;
char puzzle[105][105];
char ans[105][105];
string word="yizhong";
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,1,-1,-1,0,1};
int rec[8][2];
void solve(void)
{
	for(int i = 0;i < 8;i++)
	{
		int x = rec[i][0];
		int y = rec[i][1];
		ans[x][y] = puzzle[x][y];
	}
}

void dfs(int fx,int fy,int depth,int ddx,int ddy)
{
	if(depth == 1) rec[0][0] = fx,rec[0][1] = fy;
	if(depth == 7) solve();
	
	int x = fx + ddx;
	int y = fy + ddy;
	if(x >= 1 && x <= n && y >= 1 && y <= n && puzzle[x][y] == word[depth])
	{
		rec[depth][0] = x;
		rec[depth][1] = y;
		dfs(x,y,depth+1,ddx,ddy);
		rec[depth][0] = 0;
		rec[depth][1] = 0;
	}
	else return;
	
}

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			cin>>puzzle[i][j];
			ans[i][j] = '*';
		}
	}
	for(int i = 1 ;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(puzzle[i][j] == 'y') 
			{
				for(int u = 0;u <= 7;u++)
				{
					dfs(i,j,1,dx[u],dy[u]);
				}
			}
		}	
	}	
	for(int i = 1 ;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			cout<<ans[i][j];
		}	
		cout<< endl;
	}	
}