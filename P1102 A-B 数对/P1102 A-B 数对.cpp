#include<bits/stdc++.h>
using namespace std;
int num[200005];
int main()
{
	int n,c;
	cin>>n>>c;
	long long ans=0;
	for(int i=1;i<=n;i++) cin>>num[i];
	sort(num+1,num+1+n);
	for(int i = n; i >= 1 ; i--)
	{
		int tag = num[i] - c;
		size_t pos = lower_bound(num+1,num+1+i,tag) - num;
		size_t pos2 = upper_bound(num+1,num+1+i,tag) - num;
		ans += pos2 - pos;
		
	}
	cout<<ans<<endl;
}