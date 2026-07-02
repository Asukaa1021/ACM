#include<bits/stdc++.h>
using namespace std;

struct Stu
{
	string name;
	int a,b,c;
	
};

int A(int x)
{
	if(x<0 ) return -x;
	else return x;
}

bool Compare(string a,string b)
{
	for(int i=1;i<=a.size()&&i<=b.size();i++)
	{
		if(a[i]<b[i]) return 1;
		if(b[i]<a[i]) return 0;
	}
	if(a.size()>b.size()) return 0;
	else return 1;
}

int main()
{
	int n;
	cin>>n;
	Stu s[1005];
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].name>>s[i].a>>s[i].b>>s[i].c;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(A(s[i].a-s[j].a)<=5&&A(s[i].b-s[j].b)<=5&&A(s[i].c-s[j].c)<=5&&A((s[j].a+s[j].b+s[j].c)-(s[i].a+s[i].b+s[i].c))<=10)
			{
				cout<<s[i].name<<' '<<s[j].name<<endl;
			}
		}
	}

	return 0;
}