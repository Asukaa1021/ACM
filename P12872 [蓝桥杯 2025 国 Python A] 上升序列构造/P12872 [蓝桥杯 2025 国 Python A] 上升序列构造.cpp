#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s1,s2;
void count(string &s1,string &s2)
{
	if(s2.size() > s1.size()) return;
	if(s2.size() == s1.size() && s2 > s1) return;
	if(s1.size() == s2.size())
	{
		string newS = "";
		newS.push_back(s2[0]);
		newS.push_back('0');cnt++;
		for(int i = 1;i < s2.size();i++) newS.push_back(s2[i]);
		s2 = newS;
	}
	else
	{
		string Max = s2;
		int plus0 = s1.size() - s2.size();
		for(int i = 1;i <= plus0;i++) Max.push_back('0');
		if(Max > s1)
		{
			int len1 = s1.size(),len2 = s2.size();
			int j = 0;
			int c = 0;string res = "";
			int len = len1 - len2;
			for(int i = 0;i < len1;i++)
			{
				if(c < len)
				{
					string tmp = res + "0" + s2.substr(j);
					if(tmp > s1)
					{
						res += "0";
						c++;
						continue;
					}
				}
				if(j < len2) res += s2[j++];
			}
			
			s2 = res;
			cnt += len;
		}
		else
		{
			string newS = "";
			newS.push_back(s2[0]);
			for(int i = 1;i <= plus0 + 1;i++)
			{
				newS.push_back('0');
				cnt++;
			}
			for(int i = 1;i < s2.size();i++)
			{
				newS.push_back(s2[i]);
			}
			s2 = newS;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n;
	cin >> s1;
	for(int i = 2;i <= n;i++)
	{
		cin >> s2;
	//	cout << s1 << " %% " << s2 << endl;
		count(s1,s2);
		s1 = s2;
	//	cout << endl;
	//	cout << i << ":";
	//	cout << cnt << endl;	
	}
	cout << cnt << endl;
}
