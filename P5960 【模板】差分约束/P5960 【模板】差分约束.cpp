#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> edge(n + 2);	
	vector<bool> inQueue(n + 2);
	vector<int> cnt(n + 2);
	vector<int> dis(n + 2,INT_MAX);
	for(int i = 1;i <= m;i++)
	{
		int c1,c2,d;
		cin >> c1 >> c2 >> d;
		edge[c2].push_back({d,c1});
	}
	for(int i = 1;i <= n;i++)
	{
		edge[0].push_back({0,i});
	}
	queue<int> q;
	
	cnt[0]++;
	inQueue[0] = true;
	q.push(0);
	dis[0] = 0;
	while(!q.empty())
	{
		int u = q.front();
		inQueue[u] = false;
		q.pop();
		
		for(auto & i : edge[u])
		{
			int w = i . first;
			int v = i . second;
			if(w + dis[u] < dis[v])
			{
				dis[v] = dis[u] + w;
				if(!inQueue[v])
				{
					cnt[v]++;
					if(cnt[v] >= n) 
					{
						cout << "NO" << endl;
						return 0;
					}
					inQueue[v] = true;
					q.push(v);
				}
			}
		}
	}
	for(int i = 1;i <= n;i++) cout << dis[i] << ' ' << endl;
}