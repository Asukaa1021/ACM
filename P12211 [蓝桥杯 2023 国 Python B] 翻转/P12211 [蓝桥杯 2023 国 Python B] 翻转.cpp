#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> s;
int dp[100005][2];
int main()
{
	cin >> n;
	s.resize(n + 1);
	for(int i = 1;i <= n;i++) cin >> s[i];
	dp[1][1] = 2;
	dp[1][0] = 2;
	for(int i = 2;i <= n;i++)
	{
		dp[i][0] = min(dp[i - 1][0] - (s[i - 1][1] == s[i][0]),dp[i - 1][1] - (s[i - 1][0] == s[i][0])) + 2;
		dp[i][1] = min(dp[i - 1][0] - (s[i - 1][1] == s[i][1]),dp[i - 1][1] - (s[i - 1][0] == s[i][1])) + 2;
	}
	cout << min(dp[n][0],dp[n][1]) << endl;
}