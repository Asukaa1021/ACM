#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long ans = 0;
	string s1,s2;
	cin >> s1 >> s2;
	vector<int> pos;
	for(int i = 0;i < s1.size();i++)
	{
		if(s1[i] != s2[i]) pos.push_back(i);
	}
	for(int i = 1;i < pos.size();i += 2) ans += pos[i] - pos[i - 1];
	cout << ans << endl;
}