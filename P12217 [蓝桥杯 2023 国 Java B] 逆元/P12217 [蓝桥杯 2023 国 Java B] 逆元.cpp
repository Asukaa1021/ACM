#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int M = 2146516019;

int qpow(int d,int z)
{
	if(z == 0) return 1;
	if(z % 2 == 0) return qpow(d * d % M,z / 2);
	return qpow(d * d % M,z / 2) % M * d % M;
}

signed main()
{
	int sumXor = 1;

	for(int i = 2;i <= 233333333;i++)
	{
		int inv = qpow(i,M - 2);
		sumXor ^= inv;
	}
	cout << sumXor << endl;
}