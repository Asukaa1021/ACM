#include<bits/stdc++.h>
using namespace std;

string Plus(string a,int b)
{
	int num[500];
	stringstream S;
	string k;
	S.clear();
	S<<b;
	S>>k;
	
	memset(num,0,sizeof num);
	string c="";
	reverse(a.begin(),a.end());
	reverse(k.begin(),k.end());
	
	for(int u=0;u<k.size();u++)
	{
		for(int o=0;o<a.size();o++)
		{
			num[u+o]+=(k[u]-'0')*(a[o]-'0');
		}
		for(int o=0;o<a.size()+1;o++)
		{
			if(num[o]>9)
			{
				num[o+1]+=num[o]/10;
				num[o]%=10;
			 } 
			
		}
	}
	
		
	int x;	
	for(int u=99;u>=0;u--)
	{
		if(num[u]!=0)
		{
			x=u;
			break;
		}
	}
	
	for(int u=0;u<=x;u++)
	{
		c.push_back(num[u]+'0');
	}	
	reverse(c.begin(),c.end());
	return c;	
}


string Add(string a,string b)//有可能非只进一位
{
	string c="";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int num[200];
	memset(num,0,sizeof num);
	for(int u=0;u<a.size()||u<b.size()||num[u]!=0;u++)
	{
		if(u<a.size()) num[u]+=(a[u]-'0');
		if(u<b.size()) num[u]+=(b[u]-'0');
		num[u+1]+=num[u]/10;
		num[u]%=10;
		
		c.push_back(num[u]+'0');
	}
	reverse(c.begin(),c.end());
	return c;
}


int main()
{
	int k;
	cin>>k;
	string ans="0";
	for(int i=1;i<=k;i++)
	{
		string t="1";
		for(int j=i;j>=1;j--)
		{
			t=Plus(t,j);
		}
		
		ans=Add(ans,t);
	}
	cout<<ans<<endl; 

	
	return 0;
}
