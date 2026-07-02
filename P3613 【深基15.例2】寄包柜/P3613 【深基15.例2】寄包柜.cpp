#include<bits/stdc++.h>
using namespace std;

map<int,int> ma[1000005];

int main()
{
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int op,i,j;
		cin>>op;
		if(op==1)
		{
			cin>>i>>j;
			int k;
			cin>>k;
			ma[i][j]=k;
		}
		else
		{
			cin>>i>>j;
			if(ma[i][j]!=0) cout<<ma[i][j]<<endl;
		}
	}
	
}