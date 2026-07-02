#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,k;
	cin >> n >> k;
	vector<int> a(n),b;
	vector<bool> vis(n);
	unordered_set<int> st;
	unordered_map<int,bool> mp;
	for(int i = 0;i < n;i++) 
	{
		cin >> a[i];
		st.insert(a[i]);
	}
	sort(a.begin(),a.end());
	for(int i = 0;i < n;i++)
	{
		if(mp[a[i]]) continue;
		for(int j = a[i];j <= k;j += a[i])
		{
			if(st.count(j) == 0) 
			{
				cout << -1 << '\n';
				return;
			}
			mp[j] = true;
		}
		b.push_back(a[i]);
	}
	cout << b.size() << '\n';
	for(int i = 0;i < b.size();i++)
	{
		cout << b[i] << ' ';
	}
	cout << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}