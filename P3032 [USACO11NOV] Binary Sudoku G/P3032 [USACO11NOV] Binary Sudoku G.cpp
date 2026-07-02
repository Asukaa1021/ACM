#include<bits/stdc++.h>
using namespace std;

vector<string> ss(9);
vector<int> x(9),y(9);
vector<vector<int>> z(3,vector<int> (3));
int sum = 0;

int f()
{
	int cntx = 0,cnty = 0,cntz = 0;
	for(int i = 0;i < 9;i++)
		if(x[i] % 2 == 1) cntx++;
		
	for(int i = 0;i < 9;i++)
		if(y[i] % 2 == 1) cnty++;
		
	for(int i = 0;i < 3;i++)
		for(int j = 0;j < 3;j++)
			if(z[i][j] % 2 == 1) cntz++;

	return (cntx + cnty + cntz + 2) / 3;
}

bool check()
{
	for(int i = 0;i < 9;i++)
		if(x[i] % 2 == 1) return false;
		
	for(int i = 0;i < 9;i++)
		if(y[i] % 2 == 1) return false;
		
	for(int i = 0;i < 3;i++)
		for(int j = 0;j < 3;j++)
			if(z[i][j] % 2 == 1) return false;
			
	return true;
}

bool dfs(int bx,int dep)
{
	if(f() + dep > sum) return false;
	if(check())
	{
		cout << dep << endl;
		return true;
	}
	for(int i = bx;i < 9;i++)
	{
		for(int j = 0;j < 9;j++)
		{
			if(x[i] % 2 == 0 && y[j] % 2 == 0 && z[i / 3][j / 3] % 2 == 0) continue;
			char c = ss[i][j];
			if(c == '1') ss[i][j] = '0';
			else ss[i][j] = '1';
			x[i]++;
			y[j]++;
			z[i / 3][j / 3]++;
			if(j == 8)
			{
				if(dfs(i + 1,dep + 1)) return true;
			} 
			else 
			{
				if(dfs(i,dep + 1)) return true;
			}
			ss[i][j] = c;
			x[i]--;
			y[j]--;
			z[i / 3][j / 3]--;
		}
	}
	return false;
}

int main()
{
	int Max = 0;
	for(int i = 0;i < 9;i++) cin >> ss[i];
	for(int i = 0;i < 9;i++)
		for(int j = 0;j < 9;j++) 
			if(ss[i][j] == '1')
			{
				x[i]++;
				y[j]++;
				Max = max({Max,x[i],y[j]});
			}
	int cnt1 = 0,cnt2 = 0,cnt3 = 0;
	for(int i = 0;i < 9;i++) if(x[i] % 2 == 1) cnt1++;
	
	for(int i = 0;i < 9;i++) if(y[i] % 2 == 1) cnt2++;
	
	for(int i = 0;i <= 2;i++)
	{
		for(int j = 0;j <= 2;j++)
		{
			int x = i * 3,y = j * 3;
			int cnt = 0;
			for(int a = x;a <= x + 2;a++)
				for(int b = y;b <= y + 2;b++)
					if(ss[a][b] == '1') cnt++;

			z[i][j] = cnt;
			if(cnt % 2 == 1) cnt3++;
		}
	}
	sum = max({cnt1,cnt2,cnt3});
	if(cnt1 == 1 || cnt2 == 1)
	{
		cout << Max << endl;
		return 0;
	}
	for(int i = 0;;i++)
	{
		sum = i;
		if(dfs(0,0))
		{
			break;
		}
	}
}

