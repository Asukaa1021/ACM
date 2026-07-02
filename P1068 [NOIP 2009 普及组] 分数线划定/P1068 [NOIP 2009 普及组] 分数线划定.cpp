#include<bits/stdc++.h>
using namespace std;

struct Node{
	int k,s;	
}a[5005];

bool cmp(Node a,Node b)
{
	if(a.s==b.s) return a.k<b.k;
	return a.s>b.s;
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].k>>a[i].s;
	}
	int N=m*3/2;
	sort(a+1,a+1+n,cmp);
	int Score=a[N].s;
	for(int i=N+1;i<=n;i++)
	{
		if(a[i].s==Score) N++;
		else break;
	}
	cout<<a[N].s<<" "<<N<<endl;
	for(int i=1;i<=N;i++) cout<<a[i].k<<" "<<a[i].s<<endl;
	
	return 0;
}