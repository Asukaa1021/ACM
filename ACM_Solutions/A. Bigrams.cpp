#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin >> n;
	int cnt = 0;
	vector<int> a(n + 1);
	for(int i = 1;i <= n;i++) 
	{
		cin >> a[i];
		if(a[i] >= 3) cnt += 2;
		if(a[i] == 2) cnt++;
	}
	if(cnt >= 2) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}

signed main()
{
	int t;
	cin >> t;
	while(t--) solve();
}