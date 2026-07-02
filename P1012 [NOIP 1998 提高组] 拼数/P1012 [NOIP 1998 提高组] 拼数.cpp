#include<bits/stdc++.h>
using namespace std;

long a[25],L[25];
int n;

int Log(int x)
{
	for(int u=1;u<=21;u++)
	{
		int p=pow(10,u);
		if(x<p) return u;
	}
}

void CIN()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		L[i]=Log(a[i]);
	}
}

bool ComA(int x,int y)
{
	/*int k;
	
	if(a[x]==a[y]) return 0;
	else if(a[x]<a[y])
	{
		k=L[y]-L[x];
		int t=pow(10,k);
		if(a[x]*t<a[y]) return 1;
		else return 0;
	}
	else
	{
		k=L[x]-L[y];
		int T=pow(10,k);
		if(a[y]*T<a[x]) return 0;
		else return 1;
	} 
	*/
	if((a[x]*pow(10,L[y])+a[y])>(a[y]*pow(10,L[x])+a[x])) return false;
	else return true;
	
}

/*int ComI(int x,int y)
{
	int k;
	if(x=y) return x;
	else if(x<y){
		k=L[y]-L[x];
		if((x*pow(10,k))<y) return x;
		else return y;
	}
	else
	{
		k=L[x]-L[y];
		if((y*pow(10,k))<x) return y;
		else return x;
	} 
	
}
*/

void Sort()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-1;j++)
		{
			if(ComA(j,j+1))
			{
				int b=a[j];
				a[j]=a[j+1];
				a[j+1]=b;
				int c=L[j];
				L[j]=L[j+1];
				L[j+1]=c;
			}
		}
	}
}

void COUT()
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
	}
}

int main()
{
	CIN();
	Sort();
	COUT();
	
	return 0;
}