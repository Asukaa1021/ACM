#include<bits/stdc++.h>
using namespace std;

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

int main()
{
	int a,b,x0,y0;
	cin >> a >> b;
	int d = ex_gcd(a,b,x0,y0);
	x0 = (x0 % b + b) % b;
	cout << x0 << endl;
}
