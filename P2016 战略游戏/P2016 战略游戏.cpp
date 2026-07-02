#include<bits/stdc++.h>
using namespace std;

int n;
vector< vector<int> > tr(1505);
vector<bool> isroot(1505,true);
vector< vector<int> > dp(1505,vector<int> (5));

void DP(int root)
{
	if(tr[root].size() == 0)
	{
		dp[root][0] = 0;
		dp[root][1] = 1;
		return;
	}
	
	for(auto & v : tr[root])
	{
		DP(v);
		dp[root][1] += min(dp[v][0],dp[v][1]);
		dp[root][0] += dp[v][1];
	}
	dp[root][1]++;
}

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int u,num;
		cin >> u >> num;
		for(int j = 1;j <= num;j++)
		{
			int v;
			cin >> v;
			tr[u].push_back(v);
			isroot[v] = false;
		}
	}
	int root = -1;
	for(int i = 0;i <= n - 1;i++)
	{
		if(isroot[i])
		{
			root = i;
			break;
		}
	}
	DP(root);
	
	cout << min(dp[root][1],dp[root][0]) << endl;
	
}