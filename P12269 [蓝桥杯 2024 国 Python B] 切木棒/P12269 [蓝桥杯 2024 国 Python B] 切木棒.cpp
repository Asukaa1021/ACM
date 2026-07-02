#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,maxn;
int a[300005];
int ans;

bool check(int x)
{
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		cnt += (a[i] + x - 1) / x - 1;
	}	
	return (cnt <= m);
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) 
	{
		cin >> a[i];
		maxn = max(a[i],maxn);
	}
	
	int l = 1,r = maxn;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid))
		{
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	cout << ans << endl;
}