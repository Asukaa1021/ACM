#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,k;
	cin >> n >> k;
	vector<int> a(n + 1);
	int cnt = 0;
	map<int,int> mp;
	int maxn = 0;
	int col = 0;
	for(int i = 1;i <= n;i++) 
	{
		cin >> a[i];
		if(a[i] != a[i - 1]) 
		{
			col++;
			mp[cnt]++; //个数是cnt的有mp[cnt]种
			maxn = max(maxn,cnt);
			cnt = 0;
		}
		cnt++;
	}
	mp[cnt]++;
	maxn = max(maxn,cnt);
	mp[0] = 0;
	int ans = 0;
	int len = n;
	map<int,int> vis;
	if(k >= len && (k - len) % col == 0 && vis[col] == 0) 
	{
		ans++;
		vis[col] = true;
	}
	for(int i = 1;i < maxn;i++)//jian i ci
	{
		len -= col; //减去col个
		if(len == 0) break;
		col -= mp[i]; //如果减次数等于
		if(k >= len && (k - len) % col == 0 && vis[col] == 0) 
		{
			ans++;
			vis[col] = true;
		}
	}
	cout << ans << '\n';
}

signed main()
{
	int t;
	cin >> t;
	while(t--) solve();
}