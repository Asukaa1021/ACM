#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod = 1e9 + 7;
inline int ksm(int d,int z)
{
	if(z == 0) return 1;
	if(z % 2 == 0) return ksm(d * d % Mod,z / 2);
	else return ksm(d * d % Mod,z / 2) % Mod * d % Mod;
}

signed main()
{
	cout << (ksm(2,4042) + ksm(2,2021)) % Mod << endl;
}
