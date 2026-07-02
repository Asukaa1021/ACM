#include<bits/stdc++.h>
using namespace std;
#define int long long

int _gcd(int a,int b)
{
	if(a % b == 0) return b;
	return _gcd(b,a % b);
}

int dp[200005];
signed main()
{
	int n,g;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a.begin() + 1,a.begin() + 1 + n);
	g = _gcd(a[2],a[1]);
	for(int i = 3;i <= n;i++)
	{
		g = _gcd(a[i],g);
	}
	
	if(g != 1)
	{
		cout << "INF" << endl;
	}
	else
	{
		dp[0] = 1;
		for(int i = 1;i <= 200000;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(dp[i]) continue;
				if(a[j] <= i)
				{
					dp[i] = dp[i - a[j]];
				}
			}
		}
		int cnt = 0;
		for(int i = 1;i <= 200000;i++)
		{
			if(!dp[i]) cnt++;
		}
		cout << cnt << endl;
	}
}