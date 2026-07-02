#include<bits/stdc++.h>
using namespace std;

long long n,cnt;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	cin >> n;
	vector<long long> num(n + 1);
	vector<long long> f(n + 1);
	for(int i = 1;i <= n;i++) cin >> num[i];
	
	for(int i = 2;i <= n;i++)
	{
		f[i] = f[i - 1];
		long long x = num[i - 1];
		long long y = num[i];
		while(x > y)
		{
			y *= 2;
			f[i]++;
		}
		x = num[i - 1];
		y = num[i];
		while(x * 2 <= y)
		{
			x *= 2;
			if(f[i] > 0) f[i]--; 
		}
	}
	for(int i = 1;i <= n;i++) cnt += f[i];
	cout << cnt << endl;
}