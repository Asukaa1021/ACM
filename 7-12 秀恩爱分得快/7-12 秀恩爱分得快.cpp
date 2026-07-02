#include<bits/stdc++.h>
using namespace std;

unordered_set<string> vis;
long long cnt = 1;
int main()
{
	string s;
	cin >> s;
	for(int a = 0;a < s.size();a++)
	{
		for(int b = a + 1;b < s.size();b++)
		{
			for(int c = b + 1;c < s.size();c++)
			{
				string k = "";
				for(int p = 0;p < s.size();p++)
				{
					if(p != a && p != b && p != c) k.push_back(s[p]);
				}
				if(vis.count(k) == 0) 
				{
					cnt++;
					vis.insert(k);
				}
			}
		}
	}
	for(int b = 0;b < s.size();b++)
	{
		for(int c = b + 1;c < s.size();c++)
		{
			string k = "";
			for(int p = 0;p < s.size();p++)
			{
				if(p != b && p != c) k.push_back(s[p]);
			}
			if(vis.count(k) == 0) 
			{
				cnt++;
				vis.insert(k);
			}
		}
	}
	for(int c = 0;c < s.size();c++)
	{
		string k = "";
		for(int p = 0;p < s.size();p++)
		{
			if(p != c) k.push_back(s[p]);
		}
		if(vis.count(k) == 0) 
		{
			cnt++;
			vis.insert(k);
		}
	}
	
	cout << cnt << endl;
}
