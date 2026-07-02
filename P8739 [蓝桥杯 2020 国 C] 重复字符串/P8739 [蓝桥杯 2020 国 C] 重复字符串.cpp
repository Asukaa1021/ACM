#include<bits/stdc++.h>
using namespace std;

int n,k;
int ans = 0;

int main()
{	
	string s;
	cin >> k >> s;
	n = s.size();
	if(n % k)
	{
		cout << -1 << endl;
		return 0;
	}
	s = " " + s;
	for(int i = 1;i <= n / k;i++)
	{
		unordered_map<char,int> mp;
		int Max = 0;
		for(int j = i;j <= n;j += n / k)
		{
			Max = max(Max,++mp[s[j]]);
		}
		ans += k - Max;
	}
	cout << ans << endl;
}
