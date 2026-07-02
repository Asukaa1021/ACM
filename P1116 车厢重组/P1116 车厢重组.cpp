#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,sum=0;
	int a[10005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j]>a[i]) sum++;
		}
	}
	cout<<sum<<endl;
}