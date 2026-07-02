#include<bits/stdc++.h>
using namespace std;

int eveNum[1005];
int conNum=0;
int T[1005];
int p[3005];
int personNum[1005];
int start[1005];
int pret[1005];
int cnt[1005];

int main()
{
	int N;
	cin>>N;
	start[0]=1;
	for(int i=1;i<=N;i++)
	{
		cin>>T[i]>>personNum[i];
		start[i]=start[i-1]+personNum[i-1];
		for(int j=start[i];j<=start[i]+personNum[i]-1;j++)
		{
			cin>>p[j];
		}
	}
	for(int i=N;i>=1;i--)
	{
		int Next=i;
		do
		{
			pret[i] = Next;
			Next--;
		}while(T[i] - T[Next] < 86400 && Next>=1);
	}
	for(int j=N;j>=pret[N];j--)
	for(int i=start[j];i<=start[j]+personNum[j]-1;i++)
	{
		eveNum[p[i]]++;	
		if(eveNum[p[i]]==1) cnt[N]++;
	}
	
	for(int i=N-1;i>=1;i--)
	{
		cnt[i]=cnt[i+1];
		int k1=pret[i];//i的最前面是谁
		int k2=pret[i+1];//i+1最前面是谁
		for(int j=k1;j<=k2-1;j++)
		{
			for(int u=start[j];u<=start[j]+personNum[j]-1;u++)
			{
				eveNum[p[u]]++;//新增数
				if(eveNum[p[u]]==1) cnt[i]++;
			}
		}
		
		for(int j=start[i+1];j<=start[i+1]+personNum[i+1]-1;j++)
		{
			eveNum[p[j]]--;
			if(eveNum[p[j]] == 0) cnt[i]--;
		}
	}
	for(int i=1;i<=N;i++) cout<<cnt[i]<<endl;
}