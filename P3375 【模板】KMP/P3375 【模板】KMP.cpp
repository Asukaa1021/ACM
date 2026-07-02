#include<bits/stdc++.h>
using namespace std;

int Next[1000005];

int len1,len2;

void createNext2(string s2)
{
	Next[0]=-1;int j=-1;
	for(int i=1;i<len2;i++)
	{
		j=Next[i-1];
		while(j>=0 && s2[i]!=s2[j+1])
		{
			j=Next[j];
		}
		if(s2[i]==s2[j+1]) Next[i]=j+1;//length=j+2 next=length-1
		else Next[i]=-1;
	}
}

void KMP(string s1,string s2)
{
	int i=0;int j=0;//i s1  j s2
	while(i<len1)
	{
		
		if(s1[i]==s2[j] && j<len2 && i<len1)
		{
			i++;j++;
		}
		else if(j>=1)
		{
			j=Next[j-1]+1;
		}
		else i++;
		if(j==len2)
		{
			cout<<i-len2+1<<endl;
			j=Next[j-1]+1; //寻找下一个前缀相同的起始点
		}
	}
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	
	len1=s1.size();
	len2=s2.size();
	
	createNext2(s2);
	KMP(s1,s2);
	for(int i=0;i<len2;i++) cout<<Next[i]+1<<" ";
}