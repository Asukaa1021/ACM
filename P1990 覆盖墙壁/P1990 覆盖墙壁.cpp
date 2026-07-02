#include<bits/stdc++.h>
using namespace std;

int f[1000005];
int pref[1000005];

int main()
{
	int n;
	cin>>n;
	f[0]=1,pref[0]=1;
	f[1]=1,pref[1]=2;
	f[2]=2,pref[2]=4;
	f[3]=5,pref[3]=9;
	for(int i=4;i<=n;i++)
	{
		f[i]=f[i-1]+f[i-2]+pref[i-3]*2;
		
		pref[i]=pref[i-1]+f[i];
		f[i]%=10000;
		pref[i]%=10000;
	}
	cout<<f[n];
}