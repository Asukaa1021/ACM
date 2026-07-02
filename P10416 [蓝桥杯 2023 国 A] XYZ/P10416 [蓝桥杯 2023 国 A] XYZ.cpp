#include<bits/stdc++.h>
using namespace std;



int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long l,r;
		scanf("%lld%lld",&l,&r);
		
		if(l * 2 > r) 
		{
			cout << 0 << endl;
		}
		else
		{
			long long k = r - 2 * l + 1;
			cout << k * (k + 1) / 2 << endl;
		}
	}
	
	
}