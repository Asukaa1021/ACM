#include<bits/stdc++.h>
using namespace std;
int num[10005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i];
	sort(num+1,num+1+n);
	int sum=0;
	for(int i=2;i<=n;i++) 
	{
		int left=num[i]+num[i-1];
		sum+=left;
		num[i]=left;
		for(int j=i;j<=n-1;j++)
		{
			if(num[j]>num[j+1])
			{
				swap(num[j],num[j+1]);
			}
			else goto Next;
		}
		Next:;
	}
	cout<<sum<<endl;
}