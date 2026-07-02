#include<bits/stdc++.h>
using namespace std;

long long dp[1005][1005];

int main()
{
	string s;
	cin >> s;
	int len = s.size();
	s = " " + s;
	for(int k = 1;k <= len;k++)
	{
		for(int i = 1;i + k - 1 <= len;i++)
		{
			int l = i,r = i + k - 1;
			if(l == r) dp[l][r] = 0;
			else 
			{
				if(s[l] == s[r]) dp[l][r] = dp[l + 1][r - 1];
				else dp[l][r] = min(dp[l + 1][r],dp[l][r - 1]) + 1;
			}
		}
	}
	cout << dp[1][len] << endl;
}