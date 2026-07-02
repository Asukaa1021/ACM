#include<bits/stdc++.h>
using namespace std;
long long ans;
stringstream S;
int n=0;

long long F(string a[],int q)
{
	long long u;
	string w="";
	for(int i=1;i<=q;i++)
	{
		w+=a[i];
	}
	S.clear();
	S<<w;
	S>>u;
	return u;
}
int N[21];
string k[333];
string num[27]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","a","another","first","both","second","third"};
string m[27]={"00","01","04","09","16","25","36","49","64","81","00","21","69","96","25","56","89","24","61","00","01","01","01","04","04","09"};

int main()
{
	string s;
	int n=0;
	for(int i=1;i<=6;i++)
	{
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]>='A'&&s[i]<='Z') 
				s[i]+=-'A'+'a';
		}
		
		
		for(int j=0;j<=26;j++)
		{
			if(s==num[j])
			{
				k[++n]=m[j];
			}
		}
	}
	if(n==0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	ans=F(k,n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)
		{
			swap(k[j],k[j+1]);
			if(F(k,n)<ans)
			{
				ans=F(k,n);
			}
			else swap(k[j],k[j+1]);
		}
	}
	cout<<ans<<endl;
	
	return 0;
}