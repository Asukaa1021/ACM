#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,Min = INT_MAX;
	int c[10],p;
	cin >> n;
	for(int i = 1;i <= 9;i++)
	{
		cin >> c[i];
		if(c[i] <= Min)
		{
			Min = c[i];
			p = i;
		}
		
	}
	int res = n % Min;
	for(int i = 1;i <= n / Min;i++)
	{
		res += Min;
		for(int j = 9;j > p;j--)
		{
			if(res >= c[j])
			{
				cout << j ;
				res -= c[j];
				goto end;
			}
		}
		res-= Min;
		cout << p;
		end:;
	}
}