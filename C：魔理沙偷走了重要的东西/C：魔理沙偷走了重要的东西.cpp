#include<bits/stdc++.h>
#define int unsigned long long 
using namespace std;
int xorsum = 0;
int n;
int l = 1,r = n;

bool check1(int x)
{
	cout << "xor" << " " << 1 << " " << x << '\n';
	cout << flush;
	int res;
	cin >> res;
	return (res > 0);
}

bool check2(int x)
{
	cout << "xor" << " " << 1 << " " << x << '\n';
	cout << flush;
	int res;
	cin >> res;
	return (res == xorsum);
}

bool check3(int x)
{
	cout << "xor" << " " << 1 << " " << x << '\n';
	cout << flush;
	int res;
	cin >> res;
	return (res == 0);
}

void solve()
{
	cin >> n;
	cout << "xor" << " " << 1 << " " << n << '\n';
	cout << flush;
	cin >> xorsum;
	if(xorsum != 0) //异或和不为0，则最右区域不为0 ，pos = z处xor = xorsum
	{
		//找第一个不等于0的点 : x
		l = 1,r = n;
		int x = 1;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(check1(mid))
			{
				r = mid - 1;
				x = mid;
			}
			else l = mid + 1;
		}
		int z = n;
		l = x + 2,r = n;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(check2(mid))
			{
				r = mid - 1;
				z = mid;
			}
			else l = mid + 1;
		}
		cout << "ans" << " " << x << " " << (x ^ z ^ xorsum) << " " << z << '\n';
		cout << flush;
	}
	else
	{
		//找第一个不等于0的点 : x
		int x;
		for(int k = 1;;k++)
		{
			x = (1ull << k) - 1;
			if(check1(x)) break;
		}
		cout << "xor" << " " << 1 << " " << x << '\n';
		cout << flush;
		cin >> x;
		//找最后一个等于0的点 : z
		l = x + 2,r = n;
		int z = n;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(check3(mid))
			{
				r = mid - 1;
				z = mid;
			}
			else l = mid + 1;
		}
		cout << "ans" << " " << x << " " << (x ^ z ^ xorsum) << " " << z << '\n';
		cout << flush;
	}
}

signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}
