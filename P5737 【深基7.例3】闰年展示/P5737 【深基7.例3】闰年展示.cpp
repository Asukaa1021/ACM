#include<bits/stdc++.h>
using namespace std;

//bool R(int x)
//{
//	if(x%4==0)
//}

int main()
{
	int a,b;
	int num=0;
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		if(i%400==0||(i%4==0&&i%100!=0))
		{
			num++;
		}
	}
	cout<<num<<endl;	
	for(int i=a;i<=b;i++)
	{
		if(i%400==0||(i%4==0&&i%100!=0))
		{
			cout<<i<<" ";
		}
	}
	
	return 0;
}