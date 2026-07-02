#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int fa;
	int dis;
	int cost;
	int u;
};

int sum(int a,int b)
{
	return (a + b) * (b - a + 1) / 2;
}

vector<vector<pair<int,int>>> tr(100005);
int n;
int root = 0,Max = 0;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n ;
	for(int i = 1;i < n;i++)
	{
		int u,v,d;
		cin >> u >> v >> d;
		tr[u].push_back({v,d});
		tr[v].push_back({u,d});
	}
	queue<node> q;
	q.push({-1,0,0,1});//fa  dis  cost u
	while(!q.empty())
	{
		int f = q.front().fa;
		int dis = q.front().dis;
		int cost = q.front().cost;
		int u = q.front().u;
		q.pop();
		for(auto & k : tr[u])
		{
			int v = k.first;
			int d = k.second;
			if(v == f) continue;
			int Dis = dis + d;
			int Cost = cost + sum(dis + 1,Dis) + d * 10;
			if(Cost > Max)
			{
				Max = Cost;
				root = v;
			}
			q.push({u,Dis,Cost,v});
		}
	}
	q.push({-1,0,0,root});
	Max = 0;
	while(!q.empty())
	{
		int f = q.front().fa;
		int dis = q.front().dis;
		int cost = q.front().cost;
		int u = q.front().u;
		q.pop();
		for(auto & k : tr[u])
		{
			int v = k.first;
			int d = k.second;
			if(v == f) continue;
			int Dis = dis + d;
			int Cost = cost + sum(dis + 1,Dis) + d * 10;
			if(Cost > Max)
			{
				Max = Cost;
			}
			q.push({u,Dis,Cost,v});
		}
	}
	cout << Max << endl;
}
