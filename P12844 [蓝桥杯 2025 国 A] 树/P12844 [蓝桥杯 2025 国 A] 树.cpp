#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
vector< vector<long long> > dp;
vector< vector<int> > g;
long long ksm(long long x,long long p)
{
	if(p == 1) return x;
	if(p == 0) return 1;
	if(p % 2 == 0) return ksm(x % mod * x % mod,p / 2);
	else return ksm(x % mod * x % mod,p / 2) % mod * x % mod;
}

long long rev(long long x)
{
	return ksm(x,mod - 2);
}

void dfs(int u,int fa)
{
	dp[u][0] = 1;
	dp[u][2] = 1;
	long long res1 = 1;
	for(auto & v : g[u])
	{
		if(v == fa) continue;
		dfs(v,u);
		dp[u][0] = dp[u][0] * dp[v][2] % mod;
		dp[u][2] = (dp[u][2] * (dp[v][1] + dp[v][2]) % mod) % mod;
		res1 = res1 * (dp[v][1] + dp[v][2]) % mod;
	}
	long long res2 = 1;
	for(auto & v : g[u])
	{
		if(v == fa) continue;
		dp[u][1] = (dp[u][1] +  res1 % mod * dp[v][0] % mod * rev(dp[v][1] + dp[v][2]) % mod) % mod;
	}
}


int main()
{
	cin >> n;
	g.resize(n + 1);
	dp.resize(n + 5,vector<long long> (5));
	for(int i = 1;i < n;i++)
	{
		int v,u;
		cin >> v >> u;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	cout << (dp[1][0] + dp[1][1] + dp[1][2] - 1 + mod) % mod << endl;
}