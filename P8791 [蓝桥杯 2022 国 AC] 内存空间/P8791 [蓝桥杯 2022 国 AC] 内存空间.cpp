#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve()
{
	string s;
	int cnt = 0;
	cin >> ws;
	getline(cin,s);
	if(s[0] == 'i')
	{
		if(s.find("[]") != string::npos)
		{
			int pos = s.find("=new ");
			while(pos != string::npos)
			{
				int pos2 = s.find("[",pos);
				if(pos2 == string::npos) break;
				int k = 0;
				for(int i = pos2 + 1;i < s.size() && s[i] != ']';i++)
				{
					k = k * 10 + s[i] - '0';
				}
				cnt += 4 * k;
				if(pos + 5 > s.size() - 1) break;
				pos = s.find("=new ",pos + 1);
			}
		}
		else
		{
			int pos = s.find("=");
			while(pos != string::npos)
			{
				cnt += 4;
				if(pos + 1 > s.size() - 1) break;
				pos = s.find("=",pos + 1);
			}
		}
	}
	else if(s[0] == 'l')
	{
		if(s.find("[]") != string::npos)
		{
			int pos = s.find("=new ");
			while(pos != string::npos)
			{
				int pos2 = s.find("[",pos);
				if(pos2 == string::npos) break;
				int k = 0;
				for(int i = pos2 + 1;i < s.size() && s[i] != ']';i++)
				{
					k = k * 10 + s[i] - '0';
				}
				cnt += 8 * k;
				if(pos + 5 > s.size() - 1) break;
				pos = s.find("=new ",pos + 1);
			}
		}
		else
		{
			int pos = s.find("=");
			while(pos != string::npos)
			{
				cnt += 8;
				if(pos + 1 > s.size() - 1) break;
				pos = s.find("=",pos + 1);
			}
		}
	}
	else
	{
		int k = 0;
		for(int i = 0;i < s.size();i++)
		{
			if(s[i] == '"')
			{
				int j = i + 1;
				for(;j < s.size() && s[j] != '"';j++)
				{
					k++;
				}
				i = j;
			}
		}
		cnt += k;
	}
	return cnt;
}

void print(int x)
{
	vector<int> num;
	for(int i = 1;i <= 3;i++)
	{
		num.push_back(x % 1024);
		x = (x - x % 1024) / 1024;
	}
	num.push_back(x);
	for(int i = 3;i >= 0;i--)
	{
		if(num[i] != 0)
		{
			cout << num[i];
			if(i == 3) cout << "GB";
			if(i == 2) cout << "MB";
			if(i == 1) cout << "KB";
			if(i == 0) cout << "B";
		}
	}
}

signed main()
{
	int T;
	cin >> T;
	int ans = 0;
	while(T--) ans += solve();
	print(ans);
}
