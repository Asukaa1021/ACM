#include<bits/stdc++.h>
#define int long long
using namespace std;
const int modd = 998244353;

int ksm(int d,int z)
{
	if(z == 0) return 1ll;
	if(z % 2 == 0) return ksm(d * d % modd,z / 2);
	return ksm(d * d % modd,z / 2) % modd * d % modd;
}

struct node
{
	int len,u,v;
};

vector<node> e;

int fa[300005];

int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++) fa[i] = i;
	int connect_num = n;
	for(int i = 1;i <= m;i++)
	{
		int u,v;
		cin >> u >> v;
		e.push_back({i,u,v});
	}
	vector<bool> vis(m + 1);
	reverse(e.begin(),e.end());
	int pos = 0;
	while(connect_num >= 3 && pos < e.size())
	{
		auto [len,u,v] = e[pos];
		pos++;
		int fau = find(u);
		int fav = find(v);
		vis[len] = true;
		if(fau != fav) 
		{
			fa[fau] = fav;
			connect_num--;
		}
	}
	
	for(int i = 0;i < e.size();i++)
	{
		auto [len,u,v] = e[i];
		int fau = find(u);
		int fav = find(v);
		if(fav == fau) vis[len] = true;
	}
	int ans = 0;
	for(int i = 1;i <= m;i++)
	{
		if(!vis[i]) ans = (ans + ksm(2ll,i)) % modd;
	}
	
	cout << ans << '\n';
}
