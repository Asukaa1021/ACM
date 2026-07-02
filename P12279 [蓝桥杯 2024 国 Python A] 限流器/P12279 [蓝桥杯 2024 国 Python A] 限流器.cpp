#include<bits/stdc++.h>
using namespace std;
int n,m,l;

int main()
{
	int ans = 0;
	unordered_map<int,int> mp;
	cin >> n >> m >> l;
	for(int i = 1;i <= l;i++)
	{
		int num;
		cin >> num;
		int k = num / n;
		mp[k]++;
		if(mp[k] <= m) ans++;
	}
	cout << ans << endl;
}
