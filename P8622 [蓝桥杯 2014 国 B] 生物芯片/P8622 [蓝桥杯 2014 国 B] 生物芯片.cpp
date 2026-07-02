#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,l,r;
	cin >> n >> l >> r;
	long long L = sqrt(l);
	long long R = sqrt(r);
	long long ans = r - l + 1 - (R - L);
	cout << ans << endl;
}
