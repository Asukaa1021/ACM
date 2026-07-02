#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,m;
int num[N];
long long preAnd[N];

bool check(long long x)
{
	int begin=0;int cnt=1;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		if(preAnd[i]-preAnd[begin] > x)
		{
			cnt++;
			begin = i-1;
		}
	}
	if(cnt <= m) return true;
	return false;
}

int main()
{
	cin>>n>>m;
	int maxNum = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		maxNum = max(maxNum,num[i]);//记录最大数 作为二分左边
		preAnd[i]+=preAnd[i-1]+num[i];//前缀和
	}
	long long l=maxNum,r=preAnd[n];
	long long ans=0;
	while(l<=r)
	{
		long long mid = l+(r-l)/2;
		if(check(mid))
		{
			ans = mid;
			r = mid - 1;
		}	
		else l = mid + 1;
	}
	cout<<ans<<endl;
}