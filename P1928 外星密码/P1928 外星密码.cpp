#include<bits/stdc++.h>
using namespace std;
string sen;
string ease(int l,int r)
{
	int N=0,w=0;
	for(int i=l+1;i<=l+2;i++)
	{
		if(sen[i]<='9'&&sen[i]>='0') 
		{
			N*=10;
			N+=sen[i]-'0';
			w++;
		}
	}
	string str=sen.substr(l+w+1,r-l-1-w);
	string s="";
	for(int i=1;i<=N;i++)
	{
		s+=str;
	}
	return s;
}

int main()
{
	
	getline(cin,sen);
	int n=0;
	for(int i=0;i<sen.size();i++)
	{
		if(sen[i]=='[') n++;
	}
	while(n--)
	{
		int l=-1,r;
		for(int i=0;i<sen.size();i++)
		{
			if(sen[i]=='[') l=i;
			if(l!=-1&&sen[i]==']')
			{
				r=i;
				sen.replace(l,r-l+1,ease(l,r));
				break;
			} 
		}
	}
	cout<<sen;
}