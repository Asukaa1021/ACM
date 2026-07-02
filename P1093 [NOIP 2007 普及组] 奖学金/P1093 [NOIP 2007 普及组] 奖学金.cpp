#include<bits/stdc++.h>
using namespace std;

struct stu{
	int Yu,Shu,Ying,Xue,Zong;
}a[305];

bool cmp(stu x,stu y)
{

	if(x.Zong==y.Zong)
	{
		if(x.Yu==y.Yu) return x.Xue<y.Xue;
		return x.Yu>y.Yu;
	}
	return x.Zong>y.Zong;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].Yu>>a[i].Shu>>a[i].Ying;
		a[i].Zong=a[i].Shu+a[i].Yu+a[i].Ying;
		a[i].Xue=i;
	}
	
	sort(a+1,a+1+n,cmp);
	
	for(int i=1;i<=5;i++)
	cout<<a[i].Xue<<' '<<a[i].Zong<<endl;
}
