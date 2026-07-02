#include<bits/stdc++.h>
using namespace std;

int n;
bool vis[100005];

int main()
{
	int k1,k2;
	int Min = INT_MAX,Max = 0;
	cin >> n;
	int num;
	while(scanf("%d",&num) != EOF)
	{
		if(vis[num]) k1 = num;
		vis[num] = true;
		Min = min(num,Min);
		Max = max(num,Max);
	}
	for(int i = Min;i <= Max;i++)
	{
		if(!vis[i])
		{
			k2 = i;
			break;
		}
	}
	cout << k2 << " " << k1 << endl;
}
