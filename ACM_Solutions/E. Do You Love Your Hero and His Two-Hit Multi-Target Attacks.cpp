#include<bits/stdc++.h>
#define int long long
using namespace std;

int c[505];

void solve()
{
	int k;
	cin >> k;
	vector<int> a;
	int cnt = 1;
	while(k > 0) //c[2] = 1
	{
		int pos = lower_bound(c + 1,c + 500,k) - c;
		if(c[pos] > k) pos--;
		a.push_back(pos);
		k -= c[pos];
		cnt += pos - 1;
	}
	cout << cnt << '\n';
	
	int x = 0,y = 0;
	cout << 0 << " " << 0 << '\n';
	
	for(int i = 0;i < a.size();i++)
	{
		int num = a[i];
		if(i & 1)
		{
			for(int j = 1;j < num;j++)
			{
				cout << ++x << " " << y << '\n';
			}
		}
		else
		{
			for(int j = 1;j < num;j++)
			{
				cout << x << " " << ++y << '\n';
			}
		}
	}
}

signed main()
{	
	for(int i = 1;i <= 500;i++) c[i] = i * (i - 1) / 2;
	int t;
	cin >> t;
	while(t--) solve();
}