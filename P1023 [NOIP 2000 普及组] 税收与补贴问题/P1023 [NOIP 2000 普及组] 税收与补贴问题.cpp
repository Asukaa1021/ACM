#include<bits/stdc++.h>
using namespace std;

int Yq;
int cb,xs;
int c[10005];
int k[10005];
int b[10005];
int l=0;
int C,x;
int first;

int F(int x)
{
	int M=(Yq+x-first)*c[Yq];
	for(int i=first;c[i]>0;i++)
	{
		if(M<(i+x-first)*c[i]) return F(-x++);
	}
	return x;
}

int main()
{

	cin>>Yq>>cb>>xs;
	
	first=cb;
	while(cb!=-1&&xs!=-1)
	{
		
		C=cb;
		x=xs;
		c[cb]=xs;
		cin>>cb>>xs;
		k[++l]=(xs-x)/(cb-C);
		b[l]=x-C*k[l];
	}
	cin>>k[l];
	k[l]=-k[l];
	int p=0;
	
	for(int i=first;c[i]>0;i++)
	{
		if(c[i]!=0)
		{
			p++;
		}
		c[i]=i*k[p]+b[p];
	}
	
	int ans=F(1);
	if(ans==0) cout<<"NO SOLUTION"<<endl;
	else cout<<ans<<endl;
	
	return 0;
}
