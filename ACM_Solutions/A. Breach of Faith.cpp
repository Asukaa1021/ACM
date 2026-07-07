#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(2 * n + 1),b(2 * n + 2);
	for(int i = 1;i <= 2 * n;i++) cin >> a[i];
	sort(a.begin() + 1,a.end());
	int sum = 0;
	int pos = 2 * n;
	for(int i = 0;i <= n;i++)
	{
		int p = i * 2 + 1;
		b[p] = a[pos--];
		sum += b[p];
	}
	for(int i = n + 1;i <= 2 * n - 1;i++)
	{
		int p = (i - n) * 2;
		b[p] = a[pos--];
		sum -= b[p];
	}
	b[2 * n] = sum;
	for(int i = 1;i <= 2 * n + 1;i++)
	{
		cout << b[i] << " ";
	}
	cout << '\n';
}

signed main()
{
	int t;
	cin >> t;
	while(t--) solve();
}