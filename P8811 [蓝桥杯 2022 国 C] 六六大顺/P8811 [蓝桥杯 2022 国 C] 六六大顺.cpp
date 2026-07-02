#include<bits/stdc++.h>
using namespace std;
int n;
int num[20000005];
int main()
{
	cin >> n;
	num[0] = n * 4 % 10;
	num[1] = n * 4 / 10;
	for(int i = 1;i <= n;i++)
	{
		num[i << 1] += 4;
		num[i] -= 8;
		num[i + 1] += num[i] / 10;
		num[i] %= 10;
		if(num[i] < 0)
		{
			num[i] += 10;
			num[i + 1]--;
		}
	}
	if(num[n + 1] < 0)
	{
		num[n + 1] += 10;
		num[n + 2]--;
	}
	bool flg = false;
	for(int i = 2 * n;i >= 0;i--)
	{
		int les = num[i] % 9;
		if(i != 0) num[i - 1] += les * 10;
		num[i] /= 9;
		if(num[i] != 0) flg = true;
		if(flg) cout << num[i];
	}
}
