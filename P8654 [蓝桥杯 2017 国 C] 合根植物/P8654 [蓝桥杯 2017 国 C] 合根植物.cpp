#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt;
int fa[1000005];
bool vis[1000005];
int find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void unite(int a,int b)
{
	int faa = find(a),fab = find(b);
	if(fab == faa) return;
	fa[faa] = fab;
}

signed main()
{
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) fa[i] = i;
	
	int k;
	cin >> k;
	for(int i = 1;i <= k;i++)
	{
		int u,v;
		cin >> u >> v;
		unite(u,v);
	}
	for(int i = 1;i <= n * m;i++)
	{
		int fai = find(i);
		if(!vis[fai])
		{
			cnt++;
			vis[fai] = true;
		}
	}
	cout << cnt << endl;
}
