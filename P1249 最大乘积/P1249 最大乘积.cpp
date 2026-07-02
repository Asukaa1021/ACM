#include<bits/stdc++.h>
using namespace std;

int a[1000];
int len=0;

string Plus(string a,int b)
{
	string k="1";
	stringstream S;
	string ans="";
	S<<b;
	S>>k;
	reverse(k.begin(),k.end());
	reverse(a.begin(),a.end());
	int num[100005];
	memset(num,0,sizeof num);
	for(int i=0;i<k.size();i++)
		for(int j=0;j<a.size();j++)
		{
			num[i+j]+=(k[i]-'0')*(a[j]-'0');
			num[i+j+1]+=num[i+j]/10;
			num[i+j]%=10;
		}
	int start=0;
	for(int i=100000;i>=0;i--)
	{
		if(num[i]!=0)
		{
			start=i;
			break;
			
		}
	}	
	for(int i=start;i>=0;i--)
	{
		ans.push_back(num[i]+'0');	
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	int Num=2;
	while(n-Num>=0)
	{
		n-=Num;
		a[++len]=Num;
		Num++;
	}
	int zb=len;
	while(n>0)
	{
		n--;
		if(zb==0) zb=len;
		a[zb]++;
		zb--;
	}
	
	string A="1";
	for(int i=1;i<=len;i++)
	{
		cout<<a[i]<<" ";
		A=Plus(A,a[i]);
	}
	cout<<endl;
	cout<<A<<endl;
	
	return 0;
}