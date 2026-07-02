#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[25][13][205][2];
int n,m,len;
string s;

int dfs(int pos,int last,int sum,bool isTight)
{
	if(pos == len) return (sum <= m);
	if(sum > m) return 0;
	
	if(dp[pos][last][sum][isTight] != -1) return dp[pos][last][sum][isTight];
	
	int up = isTight ? (s[pos] - '0') : 9;
	int res = 0;
	for(int i = 0;i <= up;i++)
	{
		if(last == 10)
		{
			int new_i = (i == 0) ? 10 : i;
			int new_sum = sum;
			bool new_isTight = isTight && (i == up);
			res += dfs(pos + 1,new_i,new_sum,new_isTight);
		}
		else
		{
			int new_sum = sum + abs(last - i);
			if(new_sum > m) continue;
			bool new_isTight = isTight && (up == i);
			res += dfs(pos + 1,i,new_sum,new_isTight);
		}
	}
	return dp[pos][last][sum][isTight] = res;
}

signed main()
{
	cin >> n >> m;
	s = to_string(n);
	len = s.size();
	memset(dp,-1,sizeof dp);
	cout << dfs(0,10,0,1);
}
