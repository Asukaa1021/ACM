#include<bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<int,bool> vis;

void solve()
{
	int n;
	cin >> n;
	priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
	for(int i = 0;i < n;i++)
	{
		int len;
		cin >> len;
		vector<int> g(len);
		unordered_map<int,bool> mp;
		for(int j = len - 1;j >= 0;j--) 
		{
			cin >> g[j];
		}
		vector<int> vec;
		for(int j = 0;j < len;j++)
		{
			if(!mp[g[j]]) vec.push_back(g[j]);
			mp[g[j]] = true;
		}
		pq.push(vec);
	}
	vis.clear();
	
	for(int i = 0;i < n;i++)
	{
		vector<int> p = pq.top();
		pq.pop();
		for(int j = 0;j < p.size();j++)
		{
			if(!vis[p[j]])
			{
				vis[p[j]] = true;
				cout << p[j] << ' ';
			}
		}
		priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> tpq;
		int len = pq.size();
		while(!pq.empty())
		{
			vector<int> temp = pq.top();
			vector<int> new_vec;
			pq.pop();
			
			for(int u = 0;u < temp.size();u++)
			{
				if(!vis[temp[u]]) new_vec.push_back(temp[u]);
			}
			tpq.push(new_vec);
		}
		pq = tpq;
	}
	cout << '\n';
}


signed main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}