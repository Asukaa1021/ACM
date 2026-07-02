#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long di = 2;
	long long d = 5;
	while(n > d * 9)
	{
		n -= d * 9;
		d *= 5;
		di++;
	}
	long long ans = 0;
	for(int i = 1;i <= 9;i++)
	{
		if(n > d)
		{
			n -= d;	
		}
		else 
		{
			ans = i;
			di--;
			d /= 5;
			break;
		}
	}
	
	while(di)
	{
		long long begin = ans % 2;
		for(int i = 0 + (begin == 0);i <= 9;i += 2)
		{
			if(n > d)
			{
				n -= d;
			}
			else 
			{
				ans = ans * 10 + i;
				d /= 5;
				di--;
				break;
			}
		}
	}
	cout << ans << endl;
}