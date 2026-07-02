#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,Max;
int dp[100005];
int a[100005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	m = n;
	dp[1] = 1;
	dp[2] = 1;
	for(int i = 3;i <= n;i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		if(dp[i] > 1e6)
		{
			m = i - 1;
			break;
		}	
	 } 
	 unordered_map<int,int> mp;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= m;i++)
		if(a[i] >= dp[i] && a[i] % dp[i] == 0)
			Max = max(Max,++mp[a[i] / dp[i]]);
			
	cout << n - Max << endl;
}
