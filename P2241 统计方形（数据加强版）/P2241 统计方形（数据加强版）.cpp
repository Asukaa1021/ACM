#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,m;
	long long ans1=0,ans2=0;
	cin>>n>>m;
	int length=min(n,m);
	for(int i=1;i<=length;i++)
	{
		ans1+=(n-i+1)*(m-i+1);
	}
	ans2=(1+n)*n/2*(1+m)*m/2-ans1;
	cout<<ans1<<" "<<ans2<<endl;
}