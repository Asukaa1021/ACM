#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n;
int q[N],siz[N],cnt,num[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i];
	sort(num+1,num+1+n);
	
	for(int i=1;i<=n;i++)
	{
		int pos=lower_bound(q+1,q+1+cnt,num[i])-q;//找到第一个大于等于num[i]的元素
		while(pos < cnt && q[pos+1] == num[i]) pos++;//找到相等的最后一个
		if(pos > cnt || q[pos]!=num[i])//不能 则新开
		{
			siz[++cnt]=1;
			q[cnt]=num[i]+1;
		}
		else siz[pos]++,q[pos]++;
	}
	int Min=INT_MAX;
	for(int i=1;i<=cnt;i++) Min=min(Min,siz[i]);
	cout << Min << endl;
}