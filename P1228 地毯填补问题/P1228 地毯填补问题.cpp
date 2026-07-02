#include<bits/stdc++.h>
using namespace std;
long long x,y,a,b,l=1;
int k;

long long P(int k)
{
	for(int i=1;i<=k;i++)
	l*=2;
	return l;
}

void solve(long long x,long long y,long long a,long long b,long long l)
{
	if(l==1) return;
	if(x-a<=l/2-1 && y-b<=l/2-1)
	{
		cout<<l/2+a<<" "<<l/2+b<<" 1"<<endl;
		solve(x,y,a,b,l/2);
		solve(a+l/2,b+l/2-1,a+l/2,b,l/2);
		solve(a+l/2-1,b+l/2,a,b+l/2,l/2);
		solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
	}
	else if(x-a>l/2-1 && y-b<=l/2-1)
	{
		cout<<a+l/2-1<<" "<<l/2+b<<" 3"<<endl;
		solve(x,y,a+l/2,b,l/2);
		solve(l/2+a-1,l/2+b-1,a,b,l/2);
		solve(l/2+a-1,l/2+b,a,b+l/2,l/2);
		solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
	}
	else if(x-a<=l/2-1 && y-b>l/2-1)
	{
		cout<<l/2+a<<" "<<l/2+b-1<<" 2"<<endl;
		solve(x,y,a,b+l/2,l/2);
		solve(l/2+a-1,l/2+b-1,a,b,l/2);
		solve(l/2+a,l/2+b-1,a+l/2,b,l/2);
		solve(l/2+a,l/2+b,a+l/2,b+l/2,l/2);
	}
	else 
	{
		cout<<l/2+a-1<<" "<<l/2+b-1<<" 4"<<endl;
		solve(x,y,a+l/2,b+l/2,l/2);
		solve(l/2+a-1,l/2+b-1,a,b,l/2);
		solve(l/2+1,l/2+b-1,a+l/2,b,l/2);
		solve(l/2+a-1,l/2+b,a,b+l/2,l/2);
	}
}


int main()
{
	cin>>k>>x>>y;
	l=P(k);
	
	solve(x,y,1,1,l);
	
}