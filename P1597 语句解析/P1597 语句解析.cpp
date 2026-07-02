#include<bits/stdc++.h>
using namespace std;
int a=0,b=0,c=0;
int F(char x)
{
	if(x>='0'&&x<='9') return x-'0';
	else if(x=='a') return a;
	else if(x=='b') return b;
	else if(x=='c') return c;
}

int main()
{
	string s;
	getline(cin,s);
	
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a'&&s[i+2]=='=') a=F(s[i+3]);
		if(s[i]=='b'&&s[i+2]=='=') b=F(s[i+3]);
		if(s[i]=='c'&&s[i+2]=='=') c=F(s[i+3]);
	}
	
	cout<<a<<" "<<b<<" "<<c<<endl;
	return 0;
}