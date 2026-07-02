#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,m;
	cin>>n>>m;
	int num[1000];
	memset(num,0,sizeof num);
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		num[k]++;
	}
	

	for(int i=1;i<=999;i++)
	{
		if(num[i]!=0)
		{
			for(int j=1;j<=num[i];j++)
			{
				cout<<i<<" ";
			}
		}
	}
	
	
	return 0;
	
}