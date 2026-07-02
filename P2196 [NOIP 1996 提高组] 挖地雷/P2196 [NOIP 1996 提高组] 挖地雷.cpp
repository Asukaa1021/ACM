#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[25];
int dp[25];
vector<vector<int>> e;
int _prev[25];
int vis[25];
void dfs(int u)
{
	dp[u] = a[u];
	if(e[u].size() == 0) return;
	int pos = -1;
	for(auto v : e[u])
	{
		if(!vis[v]) dfs(v);
		vis[v] = true;
		if(pos == -1) pos = v;
		else if(dp[pos] < dp[v]) pos = v;
	}
	if(pos != -1)
	{
		dp[u] += dp[pos];
		_prev[u] = pos;
	}
}
int ans[25],ansLen;
signed main()
{
	cin >> n;
	e.resize(n + 1);
	memset(vis,0,sizeof vis);
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n - i;j++)
		{
			bool f;
			cin >> f;
			if(f)
			{
				e[min(i,j + i)].push_back(max(i,j + i));
			}
		}
	}
	int Max = 0;
	int MaxPos = -1;
	for(int i = 1;i <= n;i++)
	{
		memset(vis,0,sizeof vis);
		memset(_prev,-1,sizeof _prev);
		memset(dp,0,sizeof dp);
		vis[i] = true;
		dfs(i);
		if(MaxPos == -1) 
		{
			Max = dp[i];
			MaxPos = i;
			int len = 0;
			for(int i = MaxPos;i != -1;i = _prev[i]) 
			{
				ans[++len] = i;
			}
			ansLen = len;
		}
		else if(dp[i] > Max)
		{
			Max = dp[i];
			MaxPos = i;
			int len = 0;
			for(int i = MaxPos;i != -1;i = _prev[i]) 
			{
				ans[++len] = i;
			}
			ansLen = len;
		}
	}
	for(int i = 1;i <= ansLen;i++) cout << ans[i] << " "; 
	cout << endl;
	cout << Max << endl;
}
