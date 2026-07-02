#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	cin>>n;
	int ans;
	int k=1;
	if(n==1) cout<<'1'<<endl;
	while(n%2==0)
	{
		ans=2;
		n/=2;
	}
	
	for(int i=3;i<=sqrt(n+1);i+=2)
	{
		while(n%i==0)
		{
			ans=i;
			n/=i;
			if(n==1)
			{
				cout<<ans<<endl;
				return 0;
			 } 
		}
	}
	cout<<n<<endl;
	return 0;
}