#include<bits/stdc++.h>
using namespace std;

int value[40000];
int Min[40000];
long long sum=0;

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>value[i];
	Min[1]=value[1];
	sum+=Min[1];
	for(int i=2;i<=n;i++)
	{
		int M=INT_MAX;
		for(int j=1;j<=i-1;j++)
		{
			M=min(M,abs(value[j]-value[i]));
		}
		sum+=M;
	}
	cout<<sum<<endl;
}