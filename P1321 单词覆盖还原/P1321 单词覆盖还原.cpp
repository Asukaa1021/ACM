#include<bits/stdc++.h>
using namespace std;

bool F(string a)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!='.'&&a[i]!='*') return true;
	}
	return false;
}

int main()
{
	string s;
	cin>>s;
	int B=0,G=0;
	int len=s.size();
	
	while(F(s))
	{
		for(int i=0;i<len-2;i++)
		{
			if(((s[i]=='b'||s[i]=='*')&&(s[i+1]=='o'||s[i+1]=='*')&&(s[i+2]=='y'||s[i+2]=='*'))&&((s[i]!='*'&&s[i]!='.')||(s[i+1]!='*'&&s[i+1]!='.')||(s[i+2]!='*'&&s[i+2]!='.')) )
			{
				B++;
				s[i]='*';
				s[i+1]='*';
				s[i+2]='*';
			}
			if(((s[i]=='g'||s[i]=='*')&&(s[i+1]=='i'||s[i+1]=='*')&&(s[i+2]=='r'||s[i+2]=='*')&&(s[i+3]=='l'||s[i+3]=='*'))&&((s[i]!='*'&&s[i]!='.')||(s[i+1]!='*'&&s[i+1]!='.')||(s[i+2]!='*'&&s[i+2]!='.')||(s[i+3]!='*'&&s[i+3]!='.')) )
			{
				G++;
				s[i]='*';
				s[i+1]='*';
				s[i+2]='*';
				s[i+3]='*';
			}
		}
	
	}
	
	cout<<B<<endl<<G<<endl;
	
	return 0;
}