#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<int>> edge;

signed main()
{
	cin >> n >> m;
	edge.resize(n + 1,vector<int> (n + 1,INT_MAX));
	for(int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		edge[u][v] = min(edge[u][v],w);
		edge[v][u] = min(edge[v][u],w);
	}
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(i == j) continue;
				if(edge[i][j] > edge[i][k] + edge[k][j])
				{
					edge[j][i] = edge[i][j] = edge[i][k] + edge[k][j];
				}
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(i != j)
				cout << edge[i][j] << " ";
			else cout << 0 << " ";
		}
		cout << endl;
	}
}
