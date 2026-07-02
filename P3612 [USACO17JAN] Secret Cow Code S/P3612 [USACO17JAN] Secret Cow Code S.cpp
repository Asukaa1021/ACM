#include<bits/stdc++.h>
using namespace std;
long long n,len,l;
string s;

long long f(long long l,long long n)
{
	if(l==len)
	{
		if(n-l==1) return l;
		else return n-l-1;
	}
	else 
	{
		long long x=n-l;
		if(x==1) n=l;
		else n=x-1;
		while(l>=n&&l>len) l/=2;
		if(l>=n) return n;
		else return f(l,n);
	}
}

int main()
{
	cin>>s;
	cin>>n;
	len=s.size();
	l=len;
	while(l<n) l*=2;
	l/=2;
	
	cout<<s[f(l,n)-1];
}