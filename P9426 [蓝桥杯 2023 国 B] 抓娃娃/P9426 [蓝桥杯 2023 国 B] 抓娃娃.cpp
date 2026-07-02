#include<bits/stdc++.h>
using namespace std;

int n,m;
unordered_map<int,int> mp;
int sum[2000005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		int l,r;
		cin >> l >> r;
		mp[l + r]++;
	}	
	for(int i = 1;i <= 2000000;i++)
	{
		sum[i] = sum[i - 1] + mp[i];
	}
	for(int i = 1;i <= m;i++)
	{
		int l,r;
		cin >> l >> r;
		l *= 2;
		r *= 2;
		cout << sum[r] - sum[l - 1] << endl;
	}
}
