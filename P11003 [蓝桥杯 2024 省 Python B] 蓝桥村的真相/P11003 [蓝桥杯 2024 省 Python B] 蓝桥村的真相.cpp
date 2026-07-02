#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		if(n % 3 == 0) 
		cout << n * 2 << endl;
		else cout << n <<endl;
	}
}