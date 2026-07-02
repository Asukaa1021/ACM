#include<bits/stdc++.h>
using namespace std;

long long n;
string f[20];

void F(long long num)
{
	string str;
	stringstream S;
	S.clear();
	S<<num;
	S>>str;
	bool first=1;
	for(int i=0;i<=str.size()-1;i++)
	{
		if(str[i]=='1')
		if(first==1)
		{
			if(i+1!=str.size()-1){
				cout<<"2("<<f[str.size()-i-1]<<")";
			}
			else cout<<"2";
			first=0;
		}
		else 
		{
			if(i+1!=str.size()-1){
				cout<<"+2("<<f[str.size()-i-1]<<")";
			}
			else cout<<"+2";
		}
	}
}

long long ex(int n)
{
	
	long long num=0;
	long long res=1;
	while(n>0)
	{
		num+=res*(n%2);
		res*=10;
		n/=2;
	}//转换成二进制
	return num;
}

int main()
{
	f[0]="0";
	f[1]="2(0)";
	f[2]="2";
	f[3]="2+2(0)";
	f[4]="2(2)";
	f[5]="2(2)+2(0)";
	f[6]="2(2)+2";
	f[7]="2(2)+2+2(0)";
	f[8]="2(2+2(0))";
	f[9]="2(2+2(0))+2(0)";
	f[10]="2(2+2(0))+2";
	f[11]="2(2+2(0))+2+2(0)";
	f[12]="2(2+2(0))+2(2)";
	f[13]="2(2+2(0))+2(2)+2(0)";
	f[14]="2(2+2(0))+2(2)+2";
	f[15]="2(2+2(0))+2(2)+2+2(0)";
	cin>>n;
	long long N=ex(n);
	F(N);
}