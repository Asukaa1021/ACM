#include<bits/stdc++.h>
using namespace std;
short s[10005][10005];
short a[10005][10005];
int n,cnt = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1++,y1++,x2++,y2++;
		a[x1][y1]++;
		a[x1][y2]--;
		a[x2][y1]--;
		a[x2][y2]++;
	}
	for(int i = 1;i <= 10000;i++)
	{
		for(int j = 1;j <= 10000;j++)
		{
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
			if(s[i][j]) cnt++;
		}
	}
	cout << cnt << endl;
}
