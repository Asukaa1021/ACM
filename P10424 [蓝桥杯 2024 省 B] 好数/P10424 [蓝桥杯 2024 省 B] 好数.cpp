#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	int cnt = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int temp = i;
		for(int j = 1;temp;j++)
		{
			if(j % 2 != (temp % 10) % 2) break;
			temp /= 10;
		}
		if(temp == 0) cnt++;
	}
	cout << cnt << endl;
}