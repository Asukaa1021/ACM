#include<bits/stdc++.h>
using namespace std;

int num[10]={6,2,5,5,4,5,6,3,7,6};
int Count[3005];

int F(int x)
{
	int Cnt=0;
	stringstream S;
	S.clear();
	string s="";
	S<<x;
	S>>s;
	for(int i=0;i<s.size();i++)
	Cnt+=num[s[i]-'0'];
	return Cnt;
}

int main()
{
	int n;

	int ans=0;
	cin>>n;
	for(int i=0;i<=3000;i++)
	Count[i]=F(i);//预处理神力
	
	for(int i=0;i<=1500;i++)
		for(int j=0;j<=1500;j++)
			if(Count[i]+Count[j]+Count[i+j]+4==n) ans++;
		
	cout<<ans<<endl;	
}