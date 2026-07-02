#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a,b;
void solve()
{
	int l,r;
	cin >> l >> r;
	int n;
	n = r + 1;
	a.clear();
	for(int i = 0;i < n;i++)
	{
		a.push_back(i);
	}
	b = a;
	int sum = 0;
	int pos = r;
	while(0 <= r)
	{
		if(r == 0)
		{
			b[0] = a[0];
			break;
		}
		int k = 0;
		while((1ll << k) <= r) k++;
		int mask = (1ll << k) - 1;
		
		int clr = mask - r;
		for(int i = clr;i <= r;i++)
		{
			int p = i - clr;
			b[i] = a[r - p];
			sum += b[i] | a[i];
		}
		r = clr - 1;
	}
	cout << sum << '\n';
	for(int i = 0;i < n;i++) cout << b[i] << ' ';
	cout << '\n';
}

signed main()
{
	int t;
	cin >> t;
	while(t--) solve();
}