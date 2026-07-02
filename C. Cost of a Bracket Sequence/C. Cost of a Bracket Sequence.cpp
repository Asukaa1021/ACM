#include<bits/stdc++.h>
using namespace std;
int dp[5005][5005][2];
void solve()
{
	int n,k;
	string s;
	cin >> n >> k >> s;
	s = " " + s;
	stack<int> stk;
	vector<bool> vis;
	vis.resize(n + 1);
	for(int i = 1;i <= n;i++)
	{
		if(s[i] == '(') stk.push(i);
		else
		{
			if(stk.size())
			{
				vis[stk.top()] = true;
				stk.pop();
				vis[i] = true;
			}
		}
	}
	vector<int> ans;
	int minn = INT_MAX;
	for(int x = 0;x <= k;x++)
	{
		int yy = k - x;
		int xx = x;
		int c = 0;
		int cnt = 0;
		vector<int> temp(n + 1);
		for(int i = 1;i <= n;i++)
		{
			if(s[i] == '(')
			{
				if(xx) 
				{
					xx--;
					temp[i] = 1;
				}
			}
		}
		for(int i = n;i >= 1;i--)
		{
			if(s[i] == ')')
			{
				if(yy) 
				{
					yy--;
					temp[i] = 1;
				}
			}
		}
		for(int i = 1;i <= n;i++)
		{
			if(temp[i]) continue;
			if(s[i] == '(') c++;
			else
			{
				if(c)
				{
					c--;
					cnt++;
				}
			}
		}
		if(cnt < minn)
		{
			minn = cnt;
			ans = temp;
		}
	}
	for(int i = 1;i <= n;i++) cout << ans[i];
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) solve();
}
