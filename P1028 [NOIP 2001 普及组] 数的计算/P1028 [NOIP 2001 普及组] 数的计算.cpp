#include<bits/stdc++.h>
using namespace std;
int ans=1;
long long sum[1005];
int main()
{
	int n;
	cin>>n;
	sum[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i/2;j++)
		{
			sum[i]+=sum[j];
			
		}
		sum[i]++;
	}
	cout<<sum[n]<<endl;
}