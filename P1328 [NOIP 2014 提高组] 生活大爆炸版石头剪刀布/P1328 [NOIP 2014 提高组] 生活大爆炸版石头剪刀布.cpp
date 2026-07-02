#include<bits/stdc++.h>
using namespace std;

int a[5][5]={0,0,1,1,0,
			 1,0,0,1,0,
			 0,1,0,0,1,
			 0,0,1,0,1,
			 1,1,0,0,0};


int main()
{
	int n;
	int ra=0,rb=0;
	int Ra,Rb,aa=0,ab=0;
	cin>>n>>Ra>>Rb;
	int A[205],B[205];
	for(int i=1;i<=Ra;i++)
	cin>>A[i];
	for(int i=1;i<=Rb;i++)
	cin>>B[i];
	while(n--)
	{
		ra++;
		rb++;
		if(ra>Ra) ra=1;
		if(rb>Rb) rb=1;
		aa+=a[A[ra]][B[rb]];
		ab+=a[B[rb]][A[ra]];
	}
	
	cout<<aa<<" "<<ab<<endl;
	
	return 0;
}