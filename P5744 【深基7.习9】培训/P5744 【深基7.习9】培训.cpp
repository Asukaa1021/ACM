#include<bits/stdc++.h>
using namespace std;


string nam;
int y;
int num;	


int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>nam>>y>>num;
		if(num/5*6>600)
		cout<<nam<<" "<<(y+1)<<" "<<"600"<<endl;
		else cout<<nam<<" "<<(y+1)<<" "<<(num/5*6)<<endl;
	}
	
	return 0;
}