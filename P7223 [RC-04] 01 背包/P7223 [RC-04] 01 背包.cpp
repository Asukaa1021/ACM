#include<bits/stdc++.h>
using namespace std;
const long long Mod = 998244353;
long long ksm(long long d,long long z)
{
	if(z == 0) return 1;
	if(z % 2 == 0) return ksm(d * d % Mod,z / 2);
	else return ksm(d * d % Mod,z / 2) % Mod * d % Mod;
}

int main()
{
	int n,p;
	cin >> n >> p;
	long long ans = 1;
	for(int i = 1;i <= n;i++)
	{
		long long a;
		cin >> a;
		ans = ans * (ksm(p,a) + 1) % Mod;
	}
	cout << ans << endl;
}
