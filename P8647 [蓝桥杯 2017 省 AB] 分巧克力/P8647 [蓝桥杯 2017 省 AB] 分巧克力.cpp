#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,ans = 0;
int h[100005],w[100005];
bool check(int x)
{
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		cnt += (h[i] / x) * (w[i] / x);
	}
	return (cnt >= k);
}


signed main()
{
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> h[i] >> w[i];
	}
	int l = 1,r = 100000;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	cout << ans << endl;
}
