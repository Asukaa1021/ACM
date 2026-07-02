#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000005];
vector<int> num;
unordered_map<int,int> cnt;
signed main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(!cnt.count(a[i]))
		{
			cnt[a[i]] = 2;
			if(i == 1) cnt[a[i]] = 1;
			num.push_back(a[i]);
		}
		else
		{
			if(a[i - 1] != a[i]) cnt[a[i]]++;
			if(i == n) cnt[a[i]]--;
		}
	}
	for(int i = 0;i < num.size();i++)
	{
		num[i] *= cnt[num[i]];
	}
	sort(num.begin(),num.end());
	cout << num[0] << endl;
}
