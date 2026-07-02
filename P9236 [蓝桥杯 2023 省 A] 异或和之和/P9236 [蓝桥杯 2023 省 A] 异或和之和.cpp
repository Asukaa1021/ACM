#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int n,ans = 0;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	for(int k = 22;k >= 0;k--)
	{
		int cnt1 = 0,cnt2 = 1;
		int cnt = 0;
		int sum = 0;
		int tag = (1 << k);
		for(int i = 1;i <= n;i++)
		{
			if((a[i] & tag) == tag) cnt++;
			if(cnt % 2 == 1)
			{
				cnt1++;
				sum += cnt2;
			} 
			else
			{
				cnt2++;
				sum += cnt1;
			} 
		}
		ans += tag * sum;
	}
	cout << ans << endl;
}
