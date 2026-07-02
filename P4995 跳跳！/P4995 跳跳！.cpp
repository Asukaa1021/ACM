#include<bits/stdc++.h>
using namespace std;
int n;
long long h[305];
int main()
{
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	sort(h+1,h+1+n);
	h[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			ans+=abs((h[n-i/2]-h[i/2])*(h[n-i/2]-h[i/2]));
		}
		else
		{
			ans+=abs((h[i/2]-h[n-i/2+1])*(h[i/2]-h[n-i/2+1]));
		}
	}
	cout<<ans<<endl;
}