#include<bits/stdc++.h>
using namespace std;
struct p
{
	int s1;
}A[5005];

bool cmp(p a,p b)
{
	return a.s1<b.s1;
}
int main()
{
	int n,s,a,b;
	cin>>n>>s>>a>>b;
	int len=0;
	while(n--)
	{
		int H,S;
		cin>>H>>S;
		if(H<=a+b)	A[++len].s1=S;
	}
	
	sort(A+1,A+1+len,cmp);
	int cnt=0;
	for(int i=1;i<=len;i++)
	{
		int s2=A[i].s1;
		if(s2<=s)
		{
			s-=s2;
			cnt++;
		}
		else break;
	}
	cout<<cnt<<endl;
}