#include<bits/stdc++.h>
using namespace std;

int num[100005];
int Count[5005];
long long successContribute[5005];//数据很大要开long long

long long C(int x)//组合函数
{
	return (x-1)*x/2;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		Count[num[i]]++;
	}
	for(int i=2;i<=5000;i++)
		for(int j=1;j<=i/2;j++)
		{
			if(j==i-j) successContribute[i]+=C(Count[j]);
			else successContribute[i]+=Count[j]*Count[i-j];
		}
	
	long long ans=0;
	for(int i=1;i<=5000;i++)
	{
		if(Count[i]>=2) ans+=C(Count[i])*successContribute[i];
	}	
	cout<<(ans)%(1000000007)<<endl;
	
}