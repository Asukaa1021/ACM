#include<bits/stdc++.h>
using namespace std;

long double les = 0.0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int day;
	cin >> day;
	for(int i = 1; i <= day; i++)
	{
		long double lx = les * 0.00005;
		if(lx < 0.01 - 1e-8) 
			lx = 0;
		else 
			lx = floor(lx * 100.0 + 1e-8 * 100) / 100.0;
		
		les = les + lx;
		long double x;
		cin >> x;		
		les += x;
		
		printf("%.2Lf\n", floor((les + 1e-8) * 100) / 100);
	}
	
	return 0;
}