#include<bits/stdc++.h>
using namespace std;

string a,b;
int dp[1005][1005];

int main()
{
	cin >> a >> b;
	a = " " + a;
	b = " " + b;
	memset(dp,0x3f,sizeof dp);
	for(int i = 0;i < a.size();i++) dp[i][0] = 0;
	for(int i = 1;i < a.size();i++)
	{
		for(int j = 1;j < b.size();j++)
		{
			if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min(dp[i - 1][j],dp[i - 1][j - 1] + 1);
		}
	}
	cout << dp[a.size() - 1][b.size() - 1] << endl;
}
