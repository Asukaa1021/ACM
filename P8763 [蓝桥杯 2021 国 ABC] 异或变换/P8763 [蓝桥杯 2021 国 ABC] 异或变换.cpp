#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

int n,k,p = 1;
string s;
int num = 0;

signed main()
{
	cin >> n >> k;
	while(p < n) p *= 2;
	k %= p;
	cin >> s;
	for(int u = 1;u <= k;u++)
	{
		string new_s = s.substr(0,n - 1);
		new_s = "0" + new_s;
		for(int i = 1;i < s.size();i++)
		{
			if(s[i] == new_s[i]) s[i] = '0';
			else s[i] = '1';
		}
	}
	cout << s << endl;
}