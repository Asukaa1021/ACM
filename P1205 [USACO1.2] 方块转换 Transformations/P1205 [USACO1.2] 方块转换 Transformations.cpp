#include<bits/stdc++.h>
using namespace std;

//这个数可以是小数，分数，百分数，整数。
void f(string &x)
{
	int p=0;
	for(int i=0;i<=x.size();i++)
	{
		
		if(x[i]!='0') break;
		p++;
	}
	x=x.substr(p);
}

void F(string &x)
{
	int p=0;
	for(int i=x.size();i>=0;i--)
	{
		
		if(x[i]!='0') break;
		p++;
	}
	x=x.substr(0,x.size()-p-1);
}

int main()
{
	string a;
	int dx;
	int k=4;
	cin>>a;
	if(a=="0")
	{
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='.')
		{
			k=1;
			dx=i;
		 } 
		if(a[i]=='/')
		{
			k=2;
			dx=i;
		 } 
		if(a[i]=='%')
		{
			k=3;
		}
	}
	
	if(k==1)
	{
		string x=a.substr(0,dx);
		string y=a.substr(dx+1);
		if(x=="0") x="0";
		else 
		{
			reverse(x.begin(),x.end());
			f(x);
		}
		if(y=="0") y="0";
		else {
			
	
			f(y);
			reverse(y.begin(),y.end());
			f(y);
		}
	
		
		cout<<x<<"."<<y<<endl;
	}
	
	if(k==2)
	{
		string x=a.substr(0,dx);
		string y=a.substr(dx+1);
		if(x=="0") x="0";
		else 
		{
			reverse(x.begin(),x.end());
			f(x);
		}
	
		reverse(y.begin(),y.end());
		f(y);
		cout<<x<<"/"<<y<<endl;

	}
	if(k==3)
	{
		if(a=="0%") cout<<"0%"<<endl;
		else
		{
			reverse(a.begin(),a.end()-1);
			f(a);
			cout<<a<<endl;
		}
		
	}
	
	if(k==4)
	{
		reverse(a.begin(),a.end());
		f(a);
		
		cout<<a<<endl;
	}
	return 0;
}