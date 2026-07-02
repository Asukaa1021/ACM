#include<bits/stdc++.h>
using namespace std;

bool F(int x)
{
	for(int i=2;i<sqrt(x+1);i++)
	{
		if(x%i==0&&x!=i) return 0;
	}
	return 1;
}

int main()
{
	int n;
	cin>>n;
	int a[10005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1) continue;
		if(F(a[i])) cout<<a[i]<<" ";
 	}
	
	
	
	return 0;
}