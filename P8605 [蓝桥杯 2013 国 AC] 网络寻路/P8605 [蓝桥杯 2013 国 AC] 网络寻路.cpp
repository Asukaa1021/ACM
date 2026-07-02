#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cnt;
int deg[2000005];
vector<pair<int,int>> e;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++)
    {
    	int u,v;
    	cin >> u >> v;
    	deg[u]++;
    	deg[v]++;
    	e.push_back({u,v});
    	e.push_back({v,u});
	}
    for(auto [u,v] : e)
    {
    	int a = deg[u] - 1;
    	int b = deg[v] - 1;
    	cnt += a * b;
	}
	cout << cnt << endl;
}
