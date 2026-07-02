#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string sen;
	int n;
	cin >> sen;
	cin >> n;
	unordered_map<string,int> mp;
	for(int i = 1;i <= n;i++)
	{
		string s;
		cin >> s;
		sort(s.begin(),s.end());
		mp[s]++;
	}
	for(int i = 0; i < sen.size() - 7;i++)
	{
		string s = sen.substr(i,8);
		sort(s.begin(),s.end());
		ans += mp[s];
	}
	cout << ans << endl;
}
