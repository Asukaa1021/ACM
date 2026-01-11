#include<bits/stdc++.h>
using namespace std;
const long long N2 = 1e9 + 7;
long long ksm(long long a,long long n)
{
	if(n == 0) return 1;
	if(n == 1) return a;
	if(n % 2 == 0) return ksm(a * a %N2,n/2);
	else
	{
		return a * ksm(a  * a % N2 ,n/2) % N2;
	}
	
}

int exgcd(int a ,int b,int &x,int &y)
{
	if(!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	int x1,y1;
	int g = exgcd(b,a % b,x1,y1);
	x = y1;
	y = x1 - a/b * y1;
	return g;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long k , n;
		cin >> n >> k;
		long long sum = 0;
		int x , y;
		exgcd(k,N2,x,y);
		x = (x%N2 + N2) % N2;
		sum =(ksm(k + 1,n) - 1) % N2 * (k + 1)% N2 * x % N2;
		cout << sum << endl;
	}
}