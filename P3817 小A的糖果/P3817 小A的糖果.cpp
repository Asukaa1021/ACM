#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	int num[100005];
	int sum[100005];
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>num[i];
	for(int i=2;i<=n;i++) sum[i]=num[i]+num[i-1];
	long long cnt=0;
	for(int i=2;i<=n;i++)
	{
		if(sum[i]<=k) continue;//合格直接跳过
		else
		{
			int d=sum[i]-k;
			if(d<=num[i])//如果自己位能解决
			{
				cnt+=d;
				num[i]-=d;
				sum[i]-=d;
				sum[i+1]-=d;
			}
			else
			{
				sum[i]-=num[i];
				sum[i+1]-=num[i];
				num[i]=0;
				cnt+=d;
			}
		}
	}
	cout<<cnt<<endl;
}