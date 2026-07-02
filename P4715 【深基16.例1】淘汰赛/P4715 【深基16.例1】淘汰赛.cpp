#include<bits/stdc++.h>
using namespace std;

int tree[1000];

int main()
{
	int n;
	cin>>n;
	for(int i=pow(2,n);i<=pow(2,n+1)-1;i++) cin>>tree[i];
	for(int i=n;i>=1;i--)
	{
		for(int j=pow(2,i);j<=pow(2,i+1)-1;j+=2)
		{
			tree[j/2]=max(tree[j],tree[j+1]);
		}
	}
	int k=min(tree[2],tree[3]);
	for(int i=pow(2,n);i<=pow(2,n+1)-1;i++) if(k==tree[i])
	{
		cout<<i-pow(2,n)+1<<endl;
		break;
	}
}