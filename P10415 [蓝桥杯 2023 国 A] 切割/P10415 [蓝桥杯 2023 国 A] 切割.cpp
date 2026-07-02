#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
	if(a % b == 0) return b;
	return gcd(b,a % b);
}

int main()
{
	long long a,b,e;
	cin >> a >> b;
	long long c,d;
	c = max(a,b);
	d = min(a,b);
	e = gcd(c,d);
	for(int i = 2;i*i <= e;i++)
	{
		if(e % i == 0)
		{
			cout << a * b / i / i << endl;
			return 0;
		}
	}
	if(e == 1)
	cout << 0 << endl;
	else 
	cout << a * b / e / e << endl;
}