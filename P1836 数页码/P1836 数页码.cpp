#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,len,Sum,target;
string s;

pair<int,int> dp[15][2][2];

pair<int,int> dfs(int pos,bool is0,bool limit)
{
	if(pos == len) return {1,0};
	if(!is0 && !limit && dp[pos][is0][limit].first != -1) return dp[pos][is0][limit];
	
	int up = limit ? s[pos] - '0' : 9;
	pair<int,int> res = {0,0};
	for(int d = 0;d <= up;d++)
	{
		bool new_is0 = is0 && (d == 0);
		bool new_limit = limit && (d == up);
		
		int add = 0;
		if(!new_is0 && d == target) add = 1;
		auto ans = dfs(pos + 1,new_is0,new_limit);
		int sum = ans.first;
		int cnt = ans.second;
		
		res.first += sum;
		res.second += cnt + add * sum;
	}
	if(!is0 && !limit) return dp[pos][is0][limit] = res;
	return res;
}

signed main()
{
	cin >> n;
	s = to_string(n);
	len = s.size();
	for(int i = 1;i <= 9;i++) 
	{
		target = i;
		memset(dp,-1,sizeof dp);
		Sum += i * dfs(0,1,1).second;
	}
	cout << Sum << endl;
}
