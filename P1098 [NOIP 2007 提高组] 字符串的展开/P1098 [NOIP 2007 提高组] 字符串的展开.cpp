#include<bits/stdc++.h>
using namespace std;

int p1,p2,p3;
int a[1000];
int num=0;
int f;
string s;

bool pd(char a,char b)
{
	if(a>='0'&&a<='9'&&b>='0'&&b<='9')
	{
		if(b>a) return 1;
		else return 0;
	}
	if(a>='a'&&a<='z'&&b>='a'&&b<='z')
	{
		if(b>a) return 1;
		else return 0;
	}
	return 0;
}

string F(int x,int y,int z,int t)//t is the location of '-'
{
	string k="";
	char p=s[t-1]+1;
	for(int u=1;u<=s[t+1]-s[t-1]-1;u++)
	{
		if(s[t-1]>='0'&&s[t-1]<='9')
		{
			if(p1==3)
			{
				p='*';
				for(int j=1;j<=y;j++)	k.push_back(p);
			}
			else{
				for(int j=1;j<=y;j++)	k.push_back(p);
				p++;
			}
		}
		else
		{
			if(x==1)
			{
				if(p>='A'&&p<='Z')	p=p-'A'+'a';
				for(int j=1;j<=y;j++)	k.push_back(p);
				p++;
			}
			else if(x==2)
			{
				if(p>='a'&&p<='z') p=p-'a'+'A';
				for(int j=1;j<=y;j++)	k.push_back(p);
				p++;
			}
			else
			{
				p='*';
				for(int j=1;j<=y;j++)	k.push_back(p);
			}
		}
		
		
	}
	if(z==2)  reverse(k.begin(),k.end());
	f=k.size()-1;
	return k;
}


int main()
{
	cin>>p1>>p2>>p3;

	cin>>s;
	int n=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='-')	a[++n]=i; //a[i]为-的坐标
	}
	
	for(int i=1;i<=n;i++)
	{
		if(pd(s[a[i]+num-1],s[a[i]+num+1]))
		{
			s.replace(a[i]+num,1,F(p1,p2,p3,a[i]+num));
			num+=f;
		}
	}
	cout<<s<<endl;
	return 0;
}