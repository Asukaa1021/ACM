#include<bits/stdc++.h>
using namespace std;

string a,b;
int A[2005],B[2005],C[4010];

int main()
{
	cin>>a>>b;
	for(int i=a.size()-1;i>=0;i--)
	{
		A[a.size()-i]=a[i]-'0';
	}	
	for(int i=b.size()-1;i>=0;i--)
	{
		B[b.size()-i]=b[i]-'0';
	}
	
	for(int i=1;i<=a.size();i++)
		for(int j=1;j<=b.size();j++)
		{
			C[i+j-1]+=A[i]*B[j];
			C[i+j]+=C[i+j-1]/10;
			C[i+j-1]%=10;
		}
	int x;	
	for(int i=4005;i>=1;i--)
	{
		if(C[i]!=0)
		{
			x=i;
			break;
		}	
	}
	for(int i=x;i>=1;i--)
	{
		cout<<C[i];
	}	
	return 0;
}
