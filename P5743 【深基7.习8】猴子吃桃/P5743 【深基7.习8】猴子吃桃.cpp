#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	int ans=1;
	cin>>n;
	while(--n)
	{
		ans+=1;
		ans*=2;
	}
	cout<<ans<<endl;
}
