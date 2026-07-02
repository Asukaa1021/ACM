#include<bits/stdc++.h>
using namespace std;
#define int __int128
unordered_map<char,int> mp;

int ksm(int d, int z)
{
    int res = 1;
    while(z) 
	{
        if(z & 1) res = res * d;
        d = d * d;
        z >>= 1;
    }
    return res;
}

int read()
{
	int ss = 0;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) 
	{
		ss = ss * 10 + ch - '0';
		ch = getchar();
	}
	return ss;
}

void print(int x)
{
	if(x <= 9) putchar(x + '0');
	else
	{
		print(x / 10);
		print(x % 10);
	}
}

int change(string ss,int jz)
{
	int sum = 0;
	reverse(ss.begin(),ss.end());
	for(int i = 0;i < ss.size();i++)
	{
		sum += mp[ss[i]] * ksm(jz,i);
	}
	return sum;
}

void solve()
{
	string s;
	int b;
	cin >> s;
	b = read();
	bool f8 = true,f4 = true,f2 = true;
	int num16 = LLONG_MAX,num8 = LLONG_MAX,num4 = LLONG_MAX,num2 = LLONG_MAX;
	for(int i = 0;i < s.size();i++)
	{
		if(mp[s[i]] >= 8) f8 = false;
		if(mp[s[i]] >= 4) f4 = false;
		if(mp[s[i]] >= 2) f2 = false;
	}
	if(f2) num2 = change(s,2);
	if(f4) num4 = change(s,4);
	if(f8) num8 = change(s,8);
	num16 = change(s,16);
	int cnt = 0;
	if(num16 <= b) cnt++;
	if(num8 <= b) cnt++;
	if(num4 <= b) cnt++;
	if(num2 <= b) cnt++;
	if(cnt == 1) 
	{
		print(min(min(num2,num4),min(num8,num16)));
		cout << endl;
	}
	else cout << -1 << endl;
}

signed main()
{
	mp['0'] = 0;mp['1'] = 1;mp['2'] = 2;mp['3'] = 3;mp['4'] = 4;
	mp['5'] = 5;mp['6'] = 6;mp['7'] = 7;mp['8'] = 8;mp['9'] = 9;
	mp['A'] = 10;mp['B'] = 11;mp['C'] = 12;mp['D'] = 13;mp['E'] = 14;mp['F'] = 15;
	
	int t;
	t = read();
	while(t--) solve();
}
