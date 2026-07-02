#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int ans = 0;
signed main()
{
	cin >> s;
	vector<int> pos;
	pos.push_back(0);
	for(int i = 1;i < s.size();i++)
	{
		if(s[i - 1] > s[i] || s[i - 1] + 1 < s[i]) pos.push_back(i);
	}
	pos.push_back(s.size());
	for(int i = 1;i < pos.size() - 1;i++)
	{
		int num1 = pos[i] - pos[i - 1];
		int num2 = pos[i + 1] - pos[i];
		ans += num1 * num2;
	}
	for(int i = 1;i < pos.size();i++)
	{
		int num = pos[i] - pos[i - 1];
		ans += num * (num + 1) / 2;
	}
	cout << ans << endl;
}
