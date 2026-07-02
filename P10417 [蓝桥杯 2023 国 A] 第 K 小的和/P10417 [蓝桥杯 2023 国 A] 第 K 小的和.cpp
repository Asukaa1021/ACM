#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
vector<int> a;
vector<int> b;

inline bool check(int x)
{
	int cnt = 0;
	int p1 = 0,p2 = b.size() - 1;
	while(p1 < a.size() && a[p1] <= x)
	{
		while(p2 >= 0 && a[p1] + b[p2] > x)
		{
			p2--;
		}
		if(p1 < a.size() && p2 >= 0 && a[p1] + b[p2] <= x)
		{
			cnt += (p2 + 1);
		}
		p1++;
		if(p1 >= a.size() || p2 < 0) break;
	}
	return (cnt >= k);
}

signed main()
{
	cin >> n >> m >> k;
	a.resize(n);
	b.resize(m);
	for(int i = 0;i < n;i++) cin >> a[i];
	for(int i = 0;i < m;i++) cin >> b[i];
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int ans = a[n - 1] + b[m - 1];
	int l = 2,r = 2 * 1e9;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid))
		{
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << endl;
}
