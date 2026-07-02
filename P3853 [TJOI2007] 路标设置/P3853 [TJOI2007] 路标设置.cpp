#include<bits/stdc++.h>
using namespace std;
#define N 100005
int pos[N],dis[N];
int l,n,k;
bool check(int num,int d)
{
	if(d == 0) return false;//d不能等于0
	int sum=0;
	for(int i=n-1;i>=1;i--)
	{
		if(dis[i]>d)
		{
			int cnt = 1;
			double Dis = dis[i];//整数会向下取整
			while(Dis/cnt > d) cnt++;//计算多少次可以达成条件
			sum+=(cnt-1);
		}
		else break;
	}
	if(sum<=num) return true;
	return false;
}

int main()
{
	cin>>l>>n>>k;
	for(int i=1;i<=n;i++) cin>>pos[i];
	for(int i=1;i<=n;i++)
		if(i!=n)
		{
			dis[i]=pos[i+1]-pos[i];//保存两个之间的距离	
		}
	sort(dis+1,dis+n);
	int l=1,r=dis[n-1];
	while(l<=r)
	{
		int mid = l+(r-l)/2;
		if(check(k,mid) && (!check(k,mid-1)))
		{
			cout<<mid<<endl;
			return 0;
		}
		else if(check(k,mid))
		{
			r = mid - 1;
			continue;
		}
		else
		{
			l = mid + 1;
			continue;
		}
	}
}