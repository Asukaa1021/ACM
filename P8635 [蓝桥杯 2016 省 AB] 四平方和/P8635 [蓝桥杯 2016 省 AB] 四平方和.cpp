#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	long long n;
	cin >> n;
	int a = 0,b = 0,c = 0,d = 0;
	for(a = 0;a <= b;a++)
	{
		int aa = a * a;
		if(aa > n) break;
		for(b = a;b <= c;b++)
		{
			int bb = b * b;
			if(bb > n) break;
			for(c = b;c <= d;c++)
			{
				int cc = c * c;
				if(cc > n) break;
				for(d = c;d < 2500;d++)
				{
					int dd = d * d;
					int sum = aa + bb + cc + dd;
					if(sum > n) break;
					if(sum == n) 
					{
						cout << a << " " << b << " " << c << " " << d << endl;
						return 0;
					}
				}
			}
		}
	}
}
