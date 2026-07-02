#include<bits/stdc++.h>
using namespace std;



int F(int x,int y,int k)
{
	int l=pow(2,k);
	if(l==1) return 1;
	if(x<=l/2 && y<=l/2) return 0;
	else if(x>l/2 && y<=l/2) return F(x-l/2,y,k-1);
	else if(x<=l/2 && y>l/2) return F(x,y-l/2,k-1);
	else return F(x-l/2,y-l/2,k-1);
}

int main()
{
	int n;
	cin>>n;
	int len=pow(2,n);


	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=len;j++)
		
		{
			if(len==j) {
				
				cout<<F(i,j,n);
				break;
			}
			cout<<F(i,j,n)<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}