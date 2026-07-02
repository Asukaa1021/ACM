#include<bits/stdc++.h>
using namespace std;



int main()
{
	int n;
	string s;
	cin>>n>>s;
	int num=0;
	int Max=0;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='V'&&s[i+1]=='K') num++;
	}
	Max=num;
	num=0;
	for(int i=0;i<n;i++)
	{
		char c;
		if(s[i]=='V')
		{
			c='V';
			s[i]='K';
		} 
		else
		{
			c='K';
			s[i]='V';
		}
		for(int i=0;i<n-1;i++)
		{
			if(s[i]=='V'&&s[i+1]=='K') num++;
		}
		if(num>Max)
		 Max=num;
		s[i]=c;
		num=0;
	}
	cout<<Max<<endl;
	return 0;
}