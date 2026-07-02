#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
string s;
int dfs()
{
	if(mp.count(s)) return mp[s];
	if(s.find("LOL") != string::npos) return -1;
	if(s.find("*") == string::npos) return 0;
	int r = -1;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] == '*')
		{
			s[i] = 'L';
			int ans = dfs();
			s[i] = '*';
			if(ans == -1) return mp[s] = 1;
			if(ans == 0) r = 0; 
			s[i] = 'O';
			ans = dfs();
			s[i] = '*';
			if(ans == -1) return mp[s] = 1;
			if(ans == 0) r = 0;
		}
	}
	if(r == 0) return mp[s] = 0;
	return mp[s] = -1;
}

void solve()
{
	cin >> s;
	if(s.size() < 3) 
	{
		cout << 0 << endl;
	}
	else
	{
		int res = dfs();
		cout << res << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	while(n--) solve();
}
