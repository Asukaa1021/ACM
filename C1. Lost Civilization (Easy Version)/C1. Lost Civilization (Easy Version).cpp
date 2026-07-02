#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1;i <= n;i++) cin >> a[i];
	int Min = a[1],Max = a[1];
	int cnt = 1;
	for(int i = 2;i <= n;i++)
	{
		if(a[i] == Max + 1) Max = a[i];
		else if(a[i] > Max + 1)
		{
			cnt++;
			Max = Min = a[i];
		}
		else if(a[i] > Min && a[i] <= Max)
		{
			Max = a[i];
		}
		else
		{
			cnt++;
			Max = Min = a[i];
		}
	}
	cout << cnt << '\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}
