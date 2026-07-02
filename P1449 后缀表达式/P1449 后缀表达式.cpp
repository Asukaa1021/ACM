#include<bits/stdc++.h>
using namespace std;

int len=0;
int num[55];
char c;
int q=0;
bool b[55];

int main()
{
	int N=0;
	while(cin>>c)
	{
		if(c=='@') break;
		else if(c<='9'&&c>='0')
		{
			N=N*10+c-'0';
		} 
		else if(c=='.')
		{
			num[++len]=N;
			N=0;
		}
		else if(c=='+')
		{
			num[++len]=-1;
			b[len]=1;
			q++;
		 } 
		else if(c=='-')
		{
			num[++len]=-2;
			b[len]=1;
			q++;
		 } 
		else if(c=='*')
		{
			num[++len]=-3;
			b[len]=1;
			q++;
		 } 
		else if(c=='/')
		{
			num[++len]=-4;
			b[len]=1;
			q++;
		 } 
	}	
	while(q--)
	{
		int k;
		for(int i=1;i<=len;i++)
		{
			if(num[i]<0&&b[i]==1) 
			{
				k=i;
				goto A;
			}
		}
		A:
		int cnt=0;
		int p1,p2;
		for(int i=k-1;i>=1;i--)
		{
			if(b[i]==0&&cnt==0)
			{
				p1=i;
				cnt++;
				continue;
			 } 
			if(b[i]==0&&cnt==1) 
			{
				p2=i;
				goto _end;
			 } 
		}
		_end:
			int sum=0;
			if(num[k]==-1) sum=num[p2]+num[p1];
			else if(num[k]==-2) sum=num[p2]-num[p1];
			else if(num[k]==-3) sum=num[p2]*num[p1];
			else if(num[k]==-4) sum=num[p2]/num[p1];
		num[p2]=sum;
		b[p2]=0;	
		
		for(int i=p1;i<=len-1;i++)
		{
			num[i]=num[i+1];
			b[i]=b[i+1];
		}
		len--;k--;
		for(int i=k;i<=len-1;i++)
		{
			num[i]=num[i+1];
			b[i]=b[i+1];
		}
		len--;
	}
	cout<<num[1]<<endl;
	
}