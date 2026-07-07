#include<bits/stdc++.h>
using namespace std;

int gcd_(int a,int b)
{
	if(b > a) swap(a,b);
	if(a % b == 0) return b;
	return gcd_(b,a % b);
}

int n;
vector<vector<int>> e;
vector<int> match;
vector<bool> vis;
bool dfs(int u)
{
	for(auto & v : e[u])
	{
		if(!vis[v])
		{
			vis[v] = true;
			if(match[v] == -1 || dfs(match[v]))
			{
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	cin >> n;
	vector<int> a(2 * n + 1);
	e.resize(2 * n + 1);
	match.resize(2 * n + 1,-1);
	
	for(int i = 1;i <= 2 * n;i++) cin >> a[i];
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = n + 1;j <= 2 * n;j++)
		{
			if(gcd_(a[i],a[j]) == 1) 
			{
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		vis.assign(2 * n + 1,false);
		if(dfs(i)) cnt++;
	}
	
	if(cnt == n) cout << "Bob" << '\n';
	else cout << "Alice" << '\n';
}

