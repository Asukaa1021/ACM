#include<bits/stdc++.h>
using namespace std;

string s;
string _s;
int d[30000000];
void manacher(string ss)
{
	d[1] = 1;
	int Max = 0;
	for(int i = 2,l = 1,r = 1;i < ss.size();i++)
	{
		if(i <= r) d[i] = min(d[l + r - i],r - i);
		while(ss[i - d[i]] == ss[i + d[i]]) d[i]++;
		if(d[i] + i - 1> r) r = d[i] + i - 1,l = i - d[i] + 1;
		if(ss[i] == '#')
		{
			int len = (d[i] - 1);
			Max = max(len,Max);
		}
		else
		{
			int len = ((d[i] + 1) / 2 - 1) * 2 + 1;
			Max = max(len,Max);
		}
	}
	cout <<Max<< endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> s;
	_s.push_back('$');
	_s.push_back('#');
	for(auto c : s)
	{
		_s.push_back(c);
		_s.push_back('#');
	}
	_s.push_back('@');
	manacher(_s);
}