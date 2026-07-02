#include<bits/stdc++.h>
using namespace std;
int sum[20];

int ktl(int x)//卡特兰数递推
{
	int ans=0;
	for(int i=0;i<=x-1;i++)
	ans+=sum[i]*sum[x-i-1];
	return ans;
}

int main()
{
	int n;sum[1]=1;
	sum[0]=1;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		sum[i]=ktl(i);
	}
	cout<<sum[n]<<endl;
}