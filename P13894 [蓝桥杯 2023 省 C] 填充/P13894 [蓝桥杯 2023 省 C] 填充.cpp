#include<bits/stdc++.h>
using namespace std;

int cnt;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	string s,s1,s2;
	cin >> s;
	for(int i = 1;i < s.size();i++)
	{
		if(s[i] == s[i - 1] || s[i] == '?' || s[i - 1] == '?')
		{
			cnt++;
			i++;
		}
	}
	cout << cnt << endl;
}