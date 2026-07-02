#include<bits/stdc++.h>
using namespace std;

struct P{
	string nam;
	string job;
	int gx;
	int lev;
	int order;	
}a[115];


int cmp1(P x,P y)
{
	if(x.gx ==y.gx) return x.order<y.order;
	return x.gx>y.gx;
}

int J(string x)
{
	if(x=="BangZhu") return 1;
	if(x=="FuBangZhu") return 2;
	if(x=="HuFa") return 3;
	if(x=="ZhangLao") return 4;
	if(x=="TangZhu") return 5;
	if(x=="JingYing") return 6;
	if(x=="BangZhong") return 7;
}

int cmp2(P x,P y)
{
	if(x.job==y.job ) 
	{
		if(x.lev==y.lev ) return x.order<y.order;
		return x.lev>y.lev;
	}
	return J(x.job)<J(y.job);
}



int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].nam>>a[i].job>>a[i].gx>>a[i].lev;
		a[i].order=i;
	}
			
	sort(a+4,a+n+1,cmp1);
	
	for(int i=4;i<=n;i++)
	{
		if(i==4||i==5) a[i].job="HuFa";
		if(i>=6&&i<=9) a[i].job="ZhangLao";
		if(i>=10&&i<=16) a[i].job="TangZhu";
		if(i>=17&&i<=41) a[i].job="JingYing";
		if(i>=42) a[i].job="BangZhong";
	}
			
	sort(a+1,a+1+n,cmp2);
	
	for(int i=1;i<=n;i++)
	{
		cout<<a[i].nam<<" "<<a[i].job<<" "<<a[i].lev<<endl;
	}
	return 0;
}
