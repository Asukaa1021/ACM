#include<bits/stdc++.h>
using namespace std;

stack<char> c;
stack<char> num;
char xg[105];

bool match(char l,char r)
{
	if(l=='('&&r==')') return true;
	else if(l=='[' &&r==']') return true;
	return false;
}

int main()
{
	string s,s2;
	cin>>s;
	s2=s;
	for(int i=0;i<s.size();i++)
	{
		if(!c.empty())
		{
			if(match(c.top(),s[i]))
			{
				c.pop();
				num.pop();
			}
			else if(s[i]==')'||s[i]==']')
			{
				xg[i]=s[i];
			}
			else
			{
				c.push(s[i]);
				num.push(i);
			}
		}
		else
		{
			if(s[i]==')'||s[i]==']')
			{
				xg[i]=s[i];
			}
			else
			{
				c.push(s[i]);
				num.push(i);
			}
		}
	}
	while(!num.empty())
	{
		xg[num.top()]=c.top();
		num.pop();
		c.pop();
	}
	
	
	for(int i=100;i>=0;i--)
	{
		if(xg[i]=='[')
		{
			s2.insert(i+1,1,']');
		}
		else if(xg[i]=='(')
		{
			s2.insert(i+1,1,')');	
		}
		else if(xg[i]==')')
		{
			s2.insert(i,1,'(');	
		}
		else if(xg[i]==']')
		{
			s2.insert(i,1,'[');
		}
	}
	cout<<s2<<endl;
}