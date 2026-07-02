#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,t;
int num[100005];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int a;
		cin >> a;
		if(a != 0) num[++t] = a;
	}
	int l = 0;
	for(int i = 1;i <= t;i++)
	{
		if(num[i] == 1) 
		{
			if(l == 0)
			{
				if(i < t)
				{
					num[i + 1]++;
				}
			}
			else
			{
				if(i < t)
				{
					if(num[l] <= num[i + 1] || num[l] == 2)
					{
						num[l]++;
					}
					else
					{
						num[i + 1]++;
					}
				}
				else num[l]++;
			}
		}
		else
		{
			l = i;
		}
	}
	int ans = 1;
	for(int i = 1;i <= t;i++)
	{
		ans = (ans * num[i] % 1000000007);
	}
	cout << ans << endl;
}
