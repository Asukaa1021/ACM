#include<bits/stdc++.h>
using namespace std;
long long x,cnt;
vector<long long> bit;
long long ksm(long long d,long long z)
{
	if(z == 0) return 1;
	if(z % 2 == 0) return ksm(d * d,z / 2);
	return ksm(d * d,z / 2) * d;
}
int main()
{
	cin >> x;
	long long sum = x;
	while(x > 0)
	{
		long long xx = x % 2;
		if(xx == 0) cnt++;
		x /= 2;
	}
	cout << sum - (ksm(2,cnt)) + 1<< endl;
}
