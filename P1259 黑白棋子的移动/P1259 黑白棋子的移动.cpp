#include<bits/stdc++.h>
using namespace std;
int n;
string s;
void f(int x)
{
	s[3]='-';
	s[4]='-';
	s[8]='o';
	s[9]='*';
	cout<<s<<endl;
	s[3]='*';
	s[4]='o';
	s[7]='-';
	s[8]='-';
	cout<<s<<endl;
	s[1]='-';
	s[2]='-';
	s[7]='o';
	s[8]='o';
	cout<<s<<endl;
	s[1]='*';
	s[2]='o';
	s[6]='-';
	s[7]='-';
	cout<<s<<endl;
	s[0]='-';
	s[1]='-';
	s[6]='o';
	s[7]='*';
	cout<<s<<endl;
}

void P(int n)
{
	if(n>4)
	{
		string str=s.substr(n-1,2);
		s[n-1]='-';
		s[n]='-';
		s[2*n]=str[0];
		s[2*n+1]=str[1];
		cout<<s<<endl;
		s[n-1]='*';
		s[n]='*';
		s[2*n-2]='-';
		s[2*n-1]='-';
		cout<<s<<endl;
		P(n-1);
	}
	else f(4);
	
}


int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) s.push_back('o');
	for(int i=1;i<=n;i++) s.push_back('*');
	s.push_back('-');
	s.push_back('-');
	cout<<s<<endl;
	P(n);
}