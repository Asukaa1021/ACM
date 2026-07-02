#include<bits/stdc++.h>
using namespace std;
const long long Mod = 1000000007;
long long jc[500005];
long long invjc[500005];

long long ksm(long long x,long long d)
{
	if(d == 0) return 1;
	if(d == 1) return x % Mod;
	if(d % 2 == 0) return ksm(x * x % Mod,d / 2);
	else return ksm(x * x % Mod,d / 2) % Mod * x % Mod;
}

long long inv(long long x)
{
	return ksm(x,Mod - 2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int num;
	int nm;
	cin >> num;
	vector<int> bucket(500005);
	nm = num - 2;
	jc[0] = 1;
	for(long long i = 1;i <= 500000;i++)
	{
		jc[i] = jc[i - 1] * i % Mod;
	}
	for(long long i = 0;i <= 500000;i++)
	{
		invjc[i] = inv(jc[i]);
	}
	for(int i = 1;i <= num;i++)
	{
		int x;
		cin >> x;
		bucket[x]++;
	} 
	long long ans = 0;
	for(int i = 1;i <= nm;i++)
	{
		if(nm % i == 0 && bucket[nm / i] > 0 && bucket[i] > 0)
		{
			if(i == nm / i && bucket[i] < 2) continue;
			int n = i;
			int m = nm / i;
			bucket[n]--;
			bucket[m]--;
			long long now = jc[nm];
			for(int j = 1;j <= 500000;j++)
				if(bucket[j] > 0) 
					now = now * invjc[bucket[j]] % Mod;
			ans = (ans + now) % Mod;
			bucket[n]++;
			bucket[m]++;
		}
	}
	cout << ans << endl;
}