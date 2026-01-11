#include<bits/stdc++.h>
using namespace std;
const int m = 1e8;
int n,f;
vector<vector<int>> dp;
vector<int> num;

int main()
{
	cin >> n >> f;
	dp.resize(n + 3,vector<int> (f + 3));
	num.resize(n + 3);
	for(int i = 1;i <= n;i++)	cin >> num[i];
	dp[0][0] = 1;
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 0;j < f;j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j]) % m;
			dp[i][(j + num[i]) % f] = (dp[i - 1][j] + dp[i][(j + num[i]) % f]) % m;
		}
	}
	
	cout << ((dp[n][0] + m) - 1) % m<< endl;
}