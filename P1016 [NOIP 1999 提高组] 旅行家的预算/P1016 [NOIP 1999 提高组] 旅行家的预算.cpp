#include<bits/stdc++.h>
using namespace std;

float s,c,d,P[10],D[10];
int n;
bool T[10][10];
int M[10],N[10];
float Dis;
float price=0;
float Left=0;

void CIN()
{
	cin>>s>>c>>d>>P[1]>>n;
	D[1]=0;
	Dis=c*d;
	n++;
	D[n+1]=s;
	P[n+1]=9999;
	
	for(int i=2;i<=n;i++)
		cin>>D[i]>>P[i];
	
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			T[i][j]=0;
			if((D[j]-D[i])<=Dis) T[i][j]=1;
		}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			M[i]=0;
			N[i]=i+1;
			if(1==T[i][j]&&P[j]<=P[i])
			{
				M[i]=j;
				break;
			} 
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(0==M[i]&&P[j]<=P[N[i]]) N[i]=j;
		}
	}	
}



void F(int x)
{

	if((s-D[x])<=Dis&&0==M[x])
	{
		price+=((s-D[x])/d-Left)*P[x];
		printf("%.2f",price);
		return;
	}
	else if(M[x]>0)
	{
		price+=(((D[M[x]]-D[x])-Left)/d)*P[x];
		Left=0;
		F(M[x]);
		return;
	}
	else
	{
		price+=(c-Left)*P[x];
		Left=(c-(D[N[x]]-D[x])/d);
		F(N[x]);
		return;
	} 
}


int main()
{
	CIN();
	for(int i=1;i<=n;i++)
	{
		if(Dis<(D[i+1]-D[i]))
		{
			cout<<"No Solution"<<endl;
			return 0;
		}
	}
	
	F(1);
	
	return 0;
}