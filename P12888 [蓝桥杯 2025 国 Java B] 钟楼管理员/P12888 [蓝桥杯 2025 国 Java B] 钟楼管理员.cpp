#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		if(n % 2 == 0)
			cout << min(n / 2,k + 1) << endl;
		else
		{
			cout << min(n,k + 1) << endl;
		}
	}
}
