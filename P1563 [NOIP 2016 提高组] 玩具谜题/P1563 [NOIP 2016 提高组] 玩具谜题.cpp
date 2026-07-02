#include<bits/stdc++.h>
using namespace std;

struct P{
	string nam;
	bool f;
	int num;
}a[100005];
int n,m;


int fresh(int x)
{
	while(x<=0) x+=n;
	while(x>n) x-=n;
	return x;
	
}

int main()
{

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].f>>a[i].nam;
		a[i].num=i;
	}
	int k=1;
	for(int i=1;i<=m;i++)
	{
		bool F;
		int N;
		
		cin>>F>>N;
		if((F&&!a[k].f)||(!F&&a[k].f)) 
		{
			k+=N;
			k=fresh(k);
		}
		//if((!F&&!a[k].f)||(F&&a[k].f)) 
		else
		{
			k-=N;
			k=fresh(k);
		}
	}
	cout<<a[k].nam<<endl;
	return 0;
}
