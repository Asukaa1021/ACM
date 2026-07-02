#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int p,q;
	cin >> p >> q;
	int sum = p + 2 * q;
	for(int i = 1;i <= sqrt(sum);i++)
	{
		int res = sum - i;
		int a = 2 * i + 1;
		if(res % a == 0)
		{
			int b = res / a;
			if(abs(i - b) <= p)
			{
				cout << i << ' ' << b << '\n';
				return;
			}
		}
	}
	cout << -1 << '\n';
}

signed main()
{
	int t;
	cin >> t;
	while(t--) solve();
}