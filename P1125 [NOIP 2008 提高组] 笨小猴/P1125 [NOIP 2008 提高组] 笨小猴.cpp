#include<bits/stdc++.h>
using namespace std;

string a;
int num[30];

/*int Gcd(int x,int y)//辗转相除法
{
	if(x<y) return 1;
	if(x%y==0) return y;
	else if(x%y>y) return (x%y,y);
	else return (y,x%y);
}*/

int main()
{
	cin>>a;
	int len=a.size();
	for(int i=0;i<=len-1;i++)
	{
		num[a[i]-96]++;
	}
	sort(num+1,num+27);
	
	int k;
	for(int i=1;i<=26;i++)
	{
		if(num[i]!=0)
		{
			k=num[26]-num[i];
			break;
		}
	}
	
	if(k==0)
	{
		cout<<"No Answer\n0"<<endl;
			return 0;
	}
	for(int i=2;i<sqrt(k+1);i++)
	{
		if(k%i==0)
		{
			cout<<"No Answer\n0"<<endl;
			return 0;
		}
	}  
	
	cout<<"Lucky Word\n"<<k<<endl;

	return 0;
}
