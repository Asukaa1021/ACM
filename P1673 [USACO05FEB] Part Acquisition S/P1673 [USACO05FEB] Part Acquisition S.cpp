#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	vector<vector<int>> edge(n + 2);
	for(int i = 1;i <= n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
	}
	
	queue<int> q;
	vector<bool> inQueue(n + 2);
	vector<int> dis(n + 2,INT_MAX);
	dis[1] = 1;
	inQueue[1] = true;
	q.push(1);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		inQueue[u] = false;
		
		for(auto & v : edge[u])
		{
			if(dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				if(!inQueue[v])
				{
					q.push(v);
					inQueue[v] = true;
				}
			}
		}
	}
	if(dis[k] != INT_MAX)
	cout << dis[k] << endl;
	else cout << -1 << endl;
}