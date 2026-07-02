#include<bits/stdc++.h>
using namespace std;

int l,n,a[6000];
int H[6000],L[6000];

int Max(int x,int y)
{
	if(x<y) return y;
	else return x;
}

int Min(int x,int y)
{
	if(x<y) return x;
	else return y;
}

int main()
{
	cin>>l>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		H[i]=Max(a[i],l-a[i]+1);
		L[i]=Min(a[i],l-a[i]+1);
	}
	
	sort(H+1,H+n+1);
	sort(L+1,L+n+1);
	
	cout<<L[n]<<" "<<H[n];
	return 0;
}