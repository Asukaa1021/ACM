#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[100005];
long long sum=0;//超范围

long long f(int length)
{
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i]/length;
	}
	return sum;
}

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	 } 
	 long long ans=0;
	int l=1,r=sum/k;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(f(mid)>=k)
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans<<endl;
}