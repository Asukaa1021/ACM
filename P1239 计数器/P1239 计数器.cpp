#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
int len;
pair<int,int> dp[15][2][2];//length is0 islimit num
int target;
pair<int,int> dfs(int pos,bool is0,bool limit)
{
	if(pos == len)	return {1,0};
	if(!is0 && !limit && dp[pos][is0][limit].first != -1) return dp[pos][is0][limit];
	
	int up = (limit) ? (s[pos] - '0') : 9;
	pair<int,int> res = {0,0};
	for(int d = 0;d <= up;d++)
	{
		bool new_limit = limit && (d == up);
		bool new_is0 = is0 && (d == 0);
		int add = 0;
		if(!new_is0 && d == target) add = 1;
		auto ans = dfs(pos + 1,new_is0,new_limit);
		int ways = ans.first;
		int cNum = ans.second;
		res.first += ways;
		res.second += cNum + ways * add;
		
	}
	if(!is0 && !limit) return dp[pos][is0][limit] = res;
	return res;
}

void digitDP()
{
	cin >> n;
	s = to_string(n);
	len = s.size();
	for(int i = 0;i <= 9;i++) 
	{
		target = i;
		memset(dp,-1,sizeof dp);
		cout << dfs(0,1,1).second << endl;
	}
}

signed main()
{
	digitDP();	
}