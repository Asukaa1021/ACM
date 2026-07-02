#include<bits/stdc++.h>
using namespace std;
#define int __int128
int L;
int ans = 1e20;

int read()
{
	int s = 0;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) 
	{
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s;
}

void print(int x)
{
	if(x == 0) cout << 0;
	else
	{
		if(x > 9)
		{
			print(x / 10);
		}
		putchar(x % 10 + '0');
	}
}

int check(int mid)
{
	int m1 = mid,m2 = mid + 1;
	if(m1 % 2 == 0) m1 /= 2;
	else m2 /= 2;
	return m1 * m2;
}

signed main()
{
	L = read();
	int l = 1,r = 1e18;
	while(l <= r)
	{
		int mid = (r - l) / 2 + l;
		if(check(mid) >= L)
		{
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	while(check(ans) % 2 != L % 2) ans++;
	print(ans);
}
