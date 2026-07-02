#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt;
int main()
{
	cin >> n >> m;
	vector< vector<int> > edge(n + 1,vector<int> (n + 1,0x3f3f3f3f));
	for(int i = 1;i <= m;i++)
	{
		int u,v,s;
		cin >> u >> v >> s;
		if(edge[u][v] != 0)
		{
			edge[u][v] = min(edge[u][v],s);
		}
		else edge[u][v] = s;
		edge[v][u] = edge[u][v] ;
	}
	

	vector<int> Min(n + 1,0x3f3f3f3f);
	vector<bool> vis(n + 1,false);
	Min[1] = 0;
	int MST = 0;
	for(int i = 1;i <= n;i++)
	{
		int u = -1;
		for(int j = 1;j <= n;j++)
		{
			if(vis[j]) continue;
			if(u == -1 || Min[j] < Min[u])
			{
				u = j;
			}//找到最小边
		}
		if(Min[u] == 0x3f3f3f3f)
		{
			cout << "orz" << endl;
			return 0;
		}
		MST += Min[u];
		cnt++;
		vis[u] = true;
		for(int j = 1;j <= n;j++)
		{
			if(vis[j]) continue;
			if(edge[j][u] != 0x3f3f3f3f && Min[j] > edge[j][u])
			{
				Min[j] = edge[j][u];
			}
		}
	}
	if(cnt == n)
	{
		cout << MST << endl;
	}
	else cout << "orz" << endl;
}