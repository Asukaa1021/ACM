#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> fa;
int find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void unite(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx == fy) return;
	fa[fx] = fy;
}

void solve()
{
	cin >> n >> m;
	fa.clear();
	fa.resize(n + 1);
	for(int i = 1;i <= n;i++) fa[i] = i;
	for(int i = 1;i <= m;i++)
	{
		int u,v;
		cin >> u >> v;
		unite(u,v);
	}
	bool flg = false;
	for(int i = 1;i <= n;i++) 
		if(find(i) != find(1)) flg = true;
		
	if(!flg)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
		vector<int> st1,st2;
		for(int i = 1;i <= n;i++) 
		{
			if(find(i) == find(1)) st1.emplace_back(i);
			else st2.emplace_back(i);
		}
		for(auto u : st2)
		{
			cout << st1[0] << " " << u << endl;
		}
		for(int i = 1;i < st1.size();i++)
		{
			cout << st2[0] << " " << st1[i] << endl;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
}