#include<bits/stdc++.h>
using namespace std;

struct p
{
	int a,b;
}a[1000005];

bool cmp(p a,p b)
{
	if(a.b!=b.b) return a.b<b.b;
	return a.b-a.a<b.b-b.a;
}

int main()
{
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b;
	}
	
	sort(a+1,a+1+n,cmp);
	int k=a[1].b;
	int j=1;
	int cnt=1;
	while(j<=n)
	{
		if(a[j].a >= k)
		{
			k=a[j].b;
			cnt++;
		}
		j++;
	}
	cout<<cnt<<endl;

}