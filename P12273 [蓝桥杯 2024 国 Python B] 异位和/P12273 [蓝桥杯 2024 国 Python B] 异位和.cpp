#include<bits/stdc++.h>
using namespace std;
#define int long long
const int modd = 998244353;
int num[100005],sum;

int qpow(int d,int z)
{
	if(z == 0) return 1;
	d = (d % modd + modd) % modd;
	if(z % 2 == 0) return qpow(d * d % modd, z / 2) % modd;
	else return qpow(d * d % modd, z / 2) % modd * d % modd;
}

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

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin >> n;
	
	for(int i = 1;i <= n;i++)
	{
		cin >> num[i];
		sum = (sum + num[i]) % modd;
	}
	
	int p1,p2;
	ex_gcd(n, modd, p1, p2);
	int inv_n = (p1 % modd + modd) % modd;
	
	cin >> q;
	while(q--)
	{
		int k,x;
		cin >> k >> x;
		
		int sign = (k % 2 == 0) ? 1 : modd - 1;
		int Q = ((1 - n) % modd + modd) % modd;
		int qk = qpow(Q,k);
		int inv,y;
		ex_gcd(n,modd,inv,y);
		int s = sum * ((1 - qk) % modd + modd) % modd * inv % modd - num[x];
		s = (s % modd + modd) % modd;
		if(k % 2 == 0) s = (-s + modd) % modd;
		cout << s << '\n';
	}
	
	return 0;
}