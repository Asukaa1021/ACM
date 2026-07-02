#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n;
	cin >> n;
	int r = n % 12;
	if(r <= 9)
	{
		cout << r << ' ' << n - r << '\n';
	}
	else
	{
		for(int i = 1;i <= 9;i++)
		{
			int num = i * 11;
			if(num > n) break;
			if((n - num) % 12 == 0)
			{
				cout << num << ' ' << n - num << '\n';
				return;
			}
		}
		cout << -1 << '\n';
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
