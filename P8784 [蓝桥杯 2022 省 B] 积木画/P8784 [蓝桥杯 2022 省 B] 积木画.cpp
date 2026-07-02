#include<bits/stdc++.h>
using namespace std;
long long dp[10000005];
const long long mod = 1000000007;
int main()
{
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 5;
	for(int i = 4;i <= n;i++)
	{
		dp[i] = 2 * dp[i - 1] + dp[i - 3];
		dp[i] %= mod;
	}
	cout << dp[n] << endl;
}