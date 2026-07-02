#include<bits/stdc++.h>
using namespace std;

struct Stu
{
	string name;
	int a,b,c;
	
};

int main()
{
	int n;
	cin>>n;
	Stu s[1005];
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].name>>s[i].a>>s[i].b>>s[i].c;
	}
	
	int m=1;
	for(int i=1;i<=n;i++)
	{
		if((s[i].a+s[i].b+s[i].c)>(s[m].a+s[m].b+s[m].c))
		{
			m=i;
		
		 } 
	}
	cout<<s[m].name<<" "<<s[m].a<<" "<<s[m].b<<" "<<s[m].c;
	return 0;
}