#include<bits/stdc++.h>
using namespace std;

long long a[55];
int n,k;

void gauss()
{
	for(int i = 63;i >= 0;i--)
	{
		for(int j = k;j < n;j++)
		{
			if(a[j] >> i & 1) 
			{
				swap(a[j],a[k]);
				break;
			}
		}
		if(!(a[k] >> i & 1)) continue;
		for(int j = 0;j < n;j++)
		{
			if(j != k && (a[j] >> i & 1))
			{
				a[j] ^= a[k]; 
			}
		}
		k++;
		if(k == n) return;
	}
}

int main()
{
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	gauss();
	for(int i = 1;i < k;i++)
	{
		a[0] ^= a[i];
	}
	cout << a[0] << endl;
	
}
