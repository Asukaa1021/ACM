#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int dp[1005][1005];
vector<int> sum(1005);
const int modd = 10000;
signed main()
{
	cin >> n >> k;
	dp[1][0] = 1;
	sum[0] = 1;
	for(int i = 1;i <= k;i++) sum[i] = 1;
	for(int i = 2;i <= n;i++)
	{
		vector<int> tsum(1005);
		for(int j = 0;j <= k;j++)//逆序对总数为j
		{
			if(j >= i)
				dp[i][j] = ((sum[j] - sum[j - i]) % modd + modd) % modd;//dp 2 1 == 1
			else 
				dp[i][j] = sum[j];
			dp[i][j] %= modd;
			if(j == 0)
			{
				tsum[j] = dp[i][j];
			}	
			else 
				tsum[j] = dp[i][j] + tsum[j - 1];
			tsum[j] %= modd;
		}
		sum = tsum;
	}
	cout << dp[n][k] % modd<< endl;
}
