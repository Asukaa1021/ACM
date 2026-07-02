#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a,b,c;
int s[500005],sum[500005];
int L[500005];

inline bool check(int x,int r)
{
	int R = sum[r] - a * b * r;
	if(R > L[x]) return true;
	else return false;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> a >> b >> c;
	for(int i = 1;i <= n;i++)
	{
		cin >> s[i];
		sum[i] = sum[i - 1] + s[i];
	}
	L[1] = a * c;
	for(int i = 2;i <= n;i++)
	{
		L[i] = min(L[i - 1],sum[i - 1] - a * c * i);
	}
	int ans = 0;
	for(int R = 1;R <= n;R++)
	{
		int l = 1,r = R;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(check(mid,R))
			{
				ans = max(R - mid + 1,ans);
				r = mid - 1;
			}
			else l = mid + 1;
		}
	}
	cout << ans << endl;
}
