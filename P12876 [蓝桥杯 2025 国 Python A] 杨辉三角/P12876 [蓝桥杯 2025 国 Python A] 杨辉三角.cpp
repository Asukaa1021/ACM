#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[20020];
unordered_map<int,int> mp;
vector<int> cnt(100005);
signed main()
{
	int n;
	cin >> n;
	dp[1] = 1;
	for(int i = 2;i <= 1000;i++)
	{
		for(int j = i;j >= 1;j--)
		{
			dp[j] = dp[j] + dp[j - 1];
		//	cout << dp[j] << " ";
			mp[dp[j]]++;
		}
		//cout << endl;
	}
	for(int i = 1000;i <= n;i++) mp[i] += 2;
	for(int i = 2;i <= n;i++)
	{
		cnt[mp[i]]++;
	}

	for(int i = 1;i <= n;i++)
	{
		if(cnt[i] != 0) 
			cout << i << " " << cnt[i] << endl;
	}
}
