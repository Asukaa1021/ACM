#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	vector<int> num;
	for(int i = 0;i < s.size();i++)
	{
		num.emplace_back(s[i] - 'a' + 1);
	}
	vector<int> S = num;
	sort(S.begin(),S.end());
	long long cnt = 0;
	while(S != num)
	{
		prev_permutation(num.begin(),num.end());
		cnt++;
	}
	cout << cnt << endl;
}