#include<bits/stdc++.h>
#define int long long
using namespace std;

int query(int x)
{
	cout <<"query " << x << endl;
	int a;
	cin >> a;
	return a;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cout << "query 0" << endl;
	int n;
	cin >> n;
	
	int ans = 0;
	for(int i = 0,w = 1;i < 18;i++,w *= 10)
	{
		int l = 0,r = 9;int an = 0;
		while(l <= r)
		{
			int mid = l + r >> 1;
			int x = query(mid * w);
			
			if(x - n != mid)//加mid后进位了 说明num[i] + mid >= 10
			{
				r = mid - 1;
			}
			else //没有进位
			{
				l = mid + 1;
				an = mid;
			} 			
		}
		ans += w * (9 - an);
	}
	cout << "answer " << ans << endl;
}