#include<bits/stdc++.h>
using namespace std;
#define N 100005

int sch[N],stu[N];

int main()
{
	int schNum,stuNum;
	cin>>schNum>>stuNum;
	for(int i=1;i<=schNum;i++) cin>>sch[i];
	sort(sch+1,sch+1+schNum);
	long long ans=0;
	for(int i=1;i<=stuNum;i++)
	{
		cin>>stu[i];
		size_t pos = lower_bound(sch+1,sch+1+schNum,stu[i])-sch;
		if(pos == 1) ans+=sch[1]-stu[i];//若第一个都大于分数
		else if(pos == 1+schNum) ans+=stu[i]-sch[schNum];//若大于所有分数
		else ans+=min(sch[pos]-stu[i],stu[i]-sch[pos-1]);
	} 
	
	cout<<ans<<endl;
	
}