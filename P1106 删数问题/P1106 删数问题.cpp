#include<bits/stdc++.h>
using namespace std;

int main()
{
	string num;
	int k;
	cin>>num>>k;
	while(k--)
	{
		for(int i=0;i<num.size()-1;i++)
		{
			if(num[i]>num[i+1])
			{
				num.erase(i,1);
				goto Next;
			}
		}
		num.erase(num.size()-1,1);
		Next:;
	}
	int p;
	for(int i=0;i<num.size();i++)
	{	
		p=i;
		if(num[i]!='0')	break;	
	}
	for(int i=p;i<num.size();i++) cout<<num[i];
}