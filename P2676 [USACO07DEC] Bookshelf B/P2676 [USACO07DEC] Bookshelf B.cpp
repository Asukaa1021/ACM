#include<bits/stdc++.h>
using namespace std;



int main()
{
	int n,b;
	cin>>n>>b;
	int sum=0;
	int H[20005];
	for(int i=1;i<=n;i++)
	cin>>H[i];
	sort(H+1,H+1+n);
	for(int i=n;i>=1;i--)
	{
		sum+=H[i];
		if(sum>=b)
		{
			cout<<n-i+1<<endl;
			return 0;
		 } 
	}	
}
