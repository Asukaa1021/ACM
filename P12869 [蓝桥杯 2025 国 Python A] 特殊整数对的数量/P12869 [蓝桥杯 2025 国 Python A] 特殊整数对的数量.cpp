#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd_(int a,int b)
{
	if(b > a) swap(a,b);
	if(a % b == 0) return b;
	return gcd_(b,a % b);
}
int cnt;
signed main()
{
//	for(int i = 2025;i / 2 <= 1e6;i += 2025)
//	{
//		for(int b = i / 2;b < i && b <= 1e6;b++)
//		{
//			int a = i - b;
//			if(a < b && gcd_(a,b) == 1) cnt++;
//		}
//	}
	cout << 93816892 << endl;
}
