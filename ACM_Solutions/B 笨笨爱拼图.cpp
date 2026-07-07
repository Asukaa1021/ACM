#include<bits/stdc++.h>
#define int long long
using namespace std;


signed main()
{
	int c,e,m;
	cin >> c >> e >> m;
	
	if(c != 4)
	{
		cout << "impossible" << '\n';
		return 0;
	}
	int sum = c + e + m;
	for(int i = 2;i <= sqrt(sum);i++)
	{
		if(sum % i == 0 && m == ((i - 2) * (sum / i - 2)))
		{
			cout << max(i,sum / i) << " " << min(i,sum / i) << '\n';
			return 0;
		}
	}
	cout << "impossible" << '\n';
}
