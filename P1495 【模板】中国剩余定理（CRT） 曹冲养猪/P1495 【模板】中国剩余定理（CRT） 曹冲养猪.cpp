#include<bits/stdc++.h>
using namespace std;
#define int __int128
int read()
{
	int s = 0;
	char ch = getchar();
	while(isdigit(ch))
	{
		s = (s << 1) + (s << 3);
		s = s + (ch - '0');
		ch = getchar();
	}
	return s;
}

void print(int x)
{
	if(x == 0) cout << 0;
	int idx = 0;
	char w[30];
	while(x > 0)
	{
		w[idx++] = x % 10 + '0';
		x /= 10;
	}
	while(idx--)
	{
		putchar(w[idx]);
	}
}

int n;
int m[15],a[15];
int M = 1;
int ex_gcd(int a,int b,int &x,int &y)
{
	if(b == 0)
	{
		x = 1,y = 0;
		return a;
	}
	int d = ex_gcd(b,a % b,x,y);
	int temp = x;
	x = y;
	y = temp - a / b * y;
	return d;
}

int ChineseRemain(int n)
{
	int ans = 0;
	for(int i = 1;i <= n;i++) M *= m[i];
	for(int i = 1;i <= n;i++)
	{
		int mi = M / m[i];
		int xi,yi;
		int di = ex_gcd(mi,m[i],xi,yi);
		ans = (ans + mi * a[i] * xi) % M;
	}
	ans = (ans + M) % M;
	return ans;
}

signed main()
{
	n = read();
	for(int i = 1;i <= n;i++)
	{
		m[i] = read();
		a[i] = read();
	}	
	
	print(ChineseRemain(n));
}
