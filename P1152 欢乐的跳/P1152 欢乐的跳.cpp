#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int num[1005];
	bool b[1005];
	memset(b,0,sizeof b);
	for(int i=1;i<=n;i++) cin>>num[i];
	for(int i=1;i<n;i++)
	{
		if(abs(num[i]-num[i+1])<1005)//注意不要出界
		b[abs(num[i]-num[i+1])]=1;
	}
	for(int i=1;i<=n-1;i++)
	{
		if(b[i]==0)
		{
			cout<<"Not jolly"<<endl;
			return 0;
		}
		
	}
	cout<<"Jolly"<<endl;
	
	
}