#include<bits/stdc++.h>
using namespace std;

char c,p;
int a[10005];
int pd=1;
int l=1;
int mid;
double num,x;

int main()
{
	while(c!='=')
	{
		c=getchar();
		if(c=='+') pd=1,l++;
		else if(c=='-') pd=-1,l++;
		else if(c>='0'&&c<='9') 
		{
			a[l]=a[l]*10+(c-'0')*pd;
		}
		else if(c>='a'&&c<='z')
		{
			p=c;
			if(a[l]!=0)
			{
				x+=a[l];
				a[l]=0;
				l--;
			}
			else x+=pd;
		}
	}
	l++;
	mid=l;
	pd=1;
	l++;
	while(c!='\n')
	{
		c=getchar();
		if(c=='+') pd=1,l++;
		else if(c=='-') pd=-1,l++;
		else if(c>='0'&&c<='9') 
		{
			a[l]=a[l]*10+(c-'0')*pd;
		}
		else if(c>='a'&&c<='z')
		{
			p=c;
			if(a[l]!=0)
			{
				x-=a[l];
				a[l]=0;
				l--;
			}
			else x-=pd;
		}
		
	}
	for(int i=1;i<=l;i++)
	{
		if(i<=mid) num-=a[i];
		else num+=a[i];
	}
	if(num==0) 	printf("%c=0.000",p);//注意0除以负数为-0！！！
	else printf("%c=%.3f",p,num/x);
	return 0;
}
