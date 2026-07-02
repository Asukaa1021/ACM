#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		vector<vector<pair<long long,int>>> edge(n + 1);
		for(int i = 1;i <= m;i++)
		{
			int u,v,w;
			cin >> u >> v >> w;
			if(w >= 0)
			{
				edge[u].push_back({w,v});
				edge[v].push_back({w,u});
			}
			else
			{
				edge[u].push_back({w,v});
			}
		}
		vector<bool> inqueue(n + 2);
		vector<int> cnt(n + 2);
		vector<long long> dis(n + 2,INT_MAX);
		queue<int> q;
		q.push(1);
		dis[1] = 0;
		cnt[1] = 1;
		inqueue[1] = true;
		while(!q.empty())
		{
			int u = q.front();
			inqueue[u] = false;
			q.pop();
			
			for(auto & i : edge[u])
			{
				int v = i.second;
				int w = i.first;
				if(dis[v] > dis[u] + w)
				{
					dis[v] = dis[u] + w;
					
					if(!inqueue[v])
					{
						inqueue[v] = true;
						q.push(v);
						++cnt[v];
						if(cnt[v] >= n)
						{
							cout << "YES" << endl;
							goto End;
						} 
					}	
				}		
			}
		}
		cout << "NO" << endl;
		End:;
	}
	
}