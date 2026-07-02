#include<bits/stdc++.h>
using namespace std;
#define int __int128
int read()
{
	int s = 0,w = 1;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch))
	{
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}

void print(int x)
{
	if(x == 0)
	{
		putchar('0');
		return;
	}
	if(x > 9) print(x / 10);	
	putchar(x % 10 + '0');
}

int n;
int m[100005],a[100005];

int ex_gcd(int a,int b,int &x,int &y)
{
	if(b == 0)
	{
		x = 1,y = 0;
		return a;
	}
	int d = ex_gcd(b,a % b,y,x);
	y -= a / b * x;
	
	return d;
}

int ex_CRT()
{
	int lcm = m[1],ans = a[1];
	for(int i = 2;i <= n;i++)
	{
		int x,y;
		int d = ex_gcd(lcm,m[i],x,y);
		int delta = a[i] - ans;
		if(delta % d) return -1;
		int a1 = lcm / d;
		int b1 = m[i] / d;
		delta /= d;
		ex_gcd(a1,b1,x,y);
		x = (x % b1 + b1) % b1;
		
		int t = (delta % b1 + b1) % b1 * x % b1;
		ans = ans + t * lcm;
		lcm = lcm * m[i] / d;
	}
	return ans;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	n = read();
	for(int i = 1;i <= n;i++)
	{
		m[i] = read();
		a[i] = read();
	}
	print(ex_CRT());
}