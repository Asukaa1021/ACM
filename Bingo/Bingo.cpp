#include<bits/stdc++.h>
using namespace std;
#define int __int128

int read()
{
	int s = 0,w = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-')
		w = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		s = (s << 1) + (s << 3) + (ch - '0');
		ch = getchar();
	}
	return s * w;
}

int abs(int x)
{
	if(x < 0) return -x;
	else return x;
}

void print(int x)
{
	if(x == 0) 
	{
		cout << 0 << endl;
		return;
	}
	char w = x % 10 + '0';
	print(x / 10);
	cout << w;
}

const int Mod = 998244353;

int ex_gcd(int a,int b,int &x,int &y)
{
	if(b == 0)
	{
		x = 1,y = 0;
		return a;
	}
	int d = ex_gcd(b,a % b,y,x);
	y -= a / b * x;
	x = (x + abs(x / b) * b + b * 5) % b;
	return d;
}

void solve()
{
	int n;
	n = read();
	int p = 0;
	vector<int> a(n + 1),b(n + 1),preA(n + 1),preB(n + 1);
	for(int i = 1;i <= n;i++)
	{
		a[i] = read();
		preA[i] = preA[i - 1] + a[i];
	} 
	int q = preA[n];
	for(int i = 1;i <= n;i++)
	{
		b[i] = read();
		preB[i] = preB[i - 1] + b[i];
	} 
	for(int i = 1;i <= n;i++)
	{
		int aa = a[i],bb = b[i];
		int pB = preB[i] - bb;
		p = (p + aa * bb + aa * pB * 2);
	}
	int q_1,y,x2;
	ex_gcd(q,Mod,q_1,y);
	ex_gcd(2,Mod,x2,y);
	print(p * q_1 * x2 % Mod);
	cout << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	t = read();
	while(t--) solve();
}
