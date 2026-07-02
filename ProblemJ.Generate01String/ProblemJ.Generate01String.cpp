#include<bits/stdc++.h>
using namespace std;

string s;
int cnt = 1;
int main()
{
	cin >> s;
	int cnt1 = 0,cnt0 = 0;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] == '1') cnt1++;
		else cnt0++;
 	}
	if(cnt1 != cnt0)
	{
		cout << -1 << endl;
		return 0;
	}
	else
	{
		cout << s.size() / 2 << endl;
		int stk1 = 0,stk0 = 0;
		for(int i = 0;i < s.size();i++)
		{
			if(s[i] == '0')
			{
				if(stk0 == 0)
				{
					cout << cnt << ' ' << 1 << endl;
					stk1++;
				}
				else 
				{
					stk0--;
					cnt++;
				}
			}
			else
			{
				if(stk1 == 0)
				{
					cout << cnt << ' ' << 2 << endl;
					stk0++;
				}
				else 
				{
					stk1--;
					cnt++;
				}
			}
		}
	}
}