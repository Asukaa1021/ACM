#include<bits/stdc++.h>
using namespace std;

struct Node{
	string k;
	int num;
}a[25];

bool cmp(Node a,Node b)
{
	if(a.k.size()!=b.k.size()) return a.k.size()<b.k.size();
	for(int i=0;i<a.k.size()-1;i++)
	{
		if(a.k[i]!=b.k[i]) return a.k[i]<b.k[i];
	}
	return a.k[a.k.size()]<b.k[a.k.size()];
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].k;
		a[i].num=i;
	}
	
	sort(a+1,a+1+n,cmp);
	
	cout<<a[n].num<<endl<<a[n].k<<endl;
	
	
}