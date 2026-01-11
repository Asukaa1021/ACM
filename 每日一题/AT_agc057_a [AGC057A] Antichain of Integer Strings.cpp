#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	vector<int> f(11);
	f[1] = 1;
	for(int i = 2;i <= 10;i++)
	{
		f[i] = f[i - 1] * 10;
	}
	while(t--)
	{
		int l,r,l2,r2;
		scanf("%d%d",&l,&r);
		l2 = l;
		r2 = r;
		int len1 = 0,len2 = 0;
		while(l2 > 0)
		{
			len1++;
			l2 /= 10;
		}
		while(r2 > 0)
		{
			len2++;
			r2 /= 10;
		}
		if(len1 == len2)
		{
			printf("%d\n",r - l + 1);
		}
		else
		{
			int p = f[len2];
			if(r / p == 1)
			{
				
				printf("%d\n",r - max(r / 10,max(r % p,l - 1)));
			}
			else
			{
				printf("%d\n",r - p + 1);
			}
		}
	}
	
}