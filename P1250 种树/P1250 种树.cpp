#include<bits/stdc++.h>
using namespace std;
const int INF = -1e9;
int m,n;
struct node
{
	int v,w;
};
vector<vector<node>> edge;

int main()
{
	cin >> n >> m;
	edge.resize(n + 1);
	for(int i = 1;i <= m;i++)
	{
		int b,e,t;
		cin >> b >> e >> t;
		edge[b - 1].push_back({e,t});
	}
	for(int i = 1;i <= n;i++)
	{
		edge[i - 1].push_back({i,0});
		edge[i].push_back({i - 1,-1});
	}
	vector<int> d(n + 1,INF);
	d[0] = 0;
	vector<bool> inq(n + 1);
	queue<int> q;
	q.push(0);
	inq[0] = true;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;
		for(auto [v,w] : edge[u])
		{
			if(d[v] < d[u] + w)
			{
				d[v] = d[u] + w;
				if(!inq[v])
				{
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
	cout << d[n] << endl;
}
