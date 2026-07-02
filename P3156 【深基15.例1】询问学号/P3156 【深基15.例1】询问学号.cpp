#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[2000000];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	while(m--)
	{
		int k;
		cin>>k;
		cout<<a[k]<<endl;
	}
	
}