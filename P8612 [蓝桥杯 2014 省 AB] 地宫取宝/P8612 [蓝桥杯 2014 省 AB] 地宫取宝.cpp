#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int Mod = 1000000007;
int n,m,k;
int Map[55][55];
int cache[55][55][15][15];

int dfs(int x,int y,int depth,int Max)
{
	if(x > n || y > m) return 0;
	if(cache[x][y][depth][Max] != -1) return cache[x][y][depth][Max];
	int cnt = 0;
	if(x == n && y == m)
	{
		if(depth == k || depth == k - 1 && Map[x][y] > Max)
			cnt++;
	}
	else
	{
		cnt += dfs(x + 1,y,depth,Max);
		cnt += dfs(x,y + 1,depth,Max);
		if(Map[x][y] > Max)
		{
			cnt += dfs(x + 1,y,depth + 1,Map[x][y]);
			cnt += dfs(x,y + 1,depth + 1,Map[x][y]);
		}
			
	}
	cache[x][y][depth][Max] = cnt % Mod;
	return cache[x][y][depth][Max];
}

signed main()
{
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			cin >> Map[i][j];
			
	memset(cache,-1,sizeof cache);
	
	cout << dfs(1,1,0,-1) << endl;
}
