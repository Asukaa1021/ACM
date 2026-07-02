#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod = 911451407;
long long qpow(int d,int z)
{
	if(z == 0) return 1;
	if(z % 2 == 0) return qpow(d * d % Mod,z / 2) % Mod;
	else return qpow(d * d % Mod,z / 2) % Mod * d % Mod;
}

signed main()
{
	int n;
	cin >> n;
	cout << n % Mod * qpow(2,n - 1) % Mod << endl;
	
	
}