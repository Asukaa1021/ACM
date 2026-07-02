#include<bits/stdc++.h>

using namespace std;
int n,m;
__int128 ans = 0;

__int128 read()
{
	__int128 x = 0;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();//不能少写！！！！！！！！！！！！！！！！！！！
	while(isdigit(ch))
	{
		x *= 10;
		x += ch - '0';
		ch = getchar();
	}
	return x;
}


__int128 ksm(__int128 x,__int128 k)
{
	if(k == 0) return 1;
	if(k == 1) return x;
	if(k % 2 == 0) return ksm(x * x,k / 2);
	return x * ksm(x * x,k / 2);
}

__int128 sum(vector<__int128> q)
{
	__int128 dp[85][85][3];//dp[1 ~ m][i]  第几次  左右边界
	memset(dp,0,sizeof dp);
	__int128 Max = 0;

	for(int i = 1;i <= m;i++)
	{
		for(int j = 0;j <= i + 1;j++)
		{
			int x = j;
			int y = m + 1 - (i - j);
			for(int k = 1;k <= 2;k++)
			{
				if(k == 1 && x != 0)//zuo
				{
					dp[i][j][k] = max(dp[i - 1][j - 1][1],dp[i - 1][j - 1][2]);
					dp[i][j][k] += q[x] << i;
					Max = max(dp[i][j][k],Max);
				}
				if(k == 2 && y != m + 1)
				{
					dp[i][j][k] = max(dp[i - 1][j][1],dp[i - 1][j][2]);
					dp[i][j][k] += q[y] << i;
					Max = max(dp[i][j][k],Max);
				}
			}
		}
	}
	return Max;
}

void Print(__int128 x)
{
	if(x > 9)
	{
		Print(x / 10);
	}
	putchar(x % 10 + '0');
}

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		vector<__int128> q(m + 3);
		for(int j = 1;j <= m;j++)
		{
			q[j] = read();
		}
		ans += sum(q);
	}
	Print(ans) ;
}