#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		unordered_map<char,int> mp;
		string s1,s2,s3;
		cin >> s1 >> s2 >> s3;
		for(int i = 0;i <= 3;i++)
		{
			mp[s1[0 + i]]++;
			mp[s1[4 + i]]++;
			mp[s1[8 + i]]++;
			mp[s2[0 + i]]++;
			mp[s2[4 + i]]++;
			mp[s3[i]]++;
			int cnt = i + 1;
			if(mp['Y'] != cnt * 1 || mp['R'] != cnt * 2 || mp['G'] != cnt * 3)
			{
				cout << "NO" << endl;
				goto E;
			}
		}
		cout << "YES" << endl;
		E:;
	}
	
	
}
