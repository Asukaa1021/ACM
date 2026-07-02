#include<bits/stdc++.h>
#define int long long 
using namespace std;

void solve()
{
	int n,m;
	cin >> n >> m;
	//最小为n，最大为n * (n + 1) / 2
	if(n * (n + 1) / 2 < m || m < n) 
	{
		cout << -1 << '\n';
		return;
	}
	else
	{
		vector<bool> vis(n + 1);
		vector<int> e,e2;
		if(m == n)
		{
			cout << 1 << '\n';
			for(int i = 1;i < n;i++)
			{
				cout << i << " " << i + 1 << '\n';
			}
			return;
		}
		else if(m == n * (n + 1) / 2)
		{
			cout << n << '\n';
			for(int i = n;i > 1;i--)
			{
				cout << i << " " << i - 1 << '\n';
			}
			return;
		}
		m -= n;
		int root = -1;
		for(int i = n - 1;i >= 1;i--)
		{
			if(m >= i)
			{
				m -= i;
				vis[i + 1] = true;
				if(root == -1) root = i + 1;
				e.push_back(i + 1);
			}
		}
		cout << root << '\n';
		for(int i = 0;i < e.size() - 1;i++)
		{
			cout << e[i] << " " << e[i + 1] << '\n';
		}
		for(int i = 1;i <= n;i++)
		{
			if(!vis[i])
			{
				e2.push_back(i);
			}
		}
	
		cout << e[e.size() - 1] << " " << e2[0] << '\n';
		for(int i = 0;i < e2.size() - 1;i++)
		{
			cout << e2[i] << " " << e2[i + 1] << '\n';
		}
	}
}

signed main()
{
	int t;
	cin >> t;
	while(t--) solve();
}
