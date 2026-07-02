#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
	int n,sum = 0;
	cin >> n;
	vector<int> a(n + 3);
	vector<int> pre(n + 3),suf(n + 3);
	for(int i = 1;i <= n;i++) 
	{
		cin >> a[i];
		sum += a[i];
	}
	for(int i = 1;i <= n;i++)
		pre[i] = pre[i - 1] + abs(a[i]);
	for(int i = n;i >= 1;i--)
		suf[i] = suf[i + 1] + a[i];
	
	int maxPos = -1,maxn = -LLONG_MAX;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] > 0)
		{
			int temp = pre[i - 1] + suf[i + 1] - a[i];
			if(temp > maxn)
			{
				maxPos = i;
				maxn = temp;
			}
		}
	}
	if(sum >= maxn)
	{
		cout << 0 << '\n';
		cout << '\n';
	}
	else
	{
		vector<int> ans;
		for(int i = maxPos - 1;i >= 1;i--)
		{
			int j = i;
			if(a[j] > 0)
			{
				while(a[j] > 0 && a[j - 1] > 0) j--;
				ans.emplace_back(i);
				if(j - 1 > 0) ans.emplace_back(j - 1);
				i = j - 1;
			}
		}
		cout << ans.size() + 1 << '\n';
		for(int i = 0;i < ans.size();i++)
			cout << ans[i] << ' ';
		cout << maxPos;
		cout << '\n';
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
}