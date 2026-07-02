#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
int p[1000005];
bool isPrime[1000005];
int ans = INT_MAX;
bool vis[1000005];
void linearSieve(int n)
{
	fill(isPrime,isPrime + n + 1,true);
	isPrime[0] = false;
	isPrime[1] = false;
	for(int i = 2;i <= n;i++)
	{
		if(isPrime[i])
		{
			prime.push_back(i);
			p[i] = i;
		}
		for(int j = 0;j < prime.size() && i * prime[j] <= n;j++)
		{
			isPrime[prime[j] * i] = false;
			p[prime[j] * i] = max(p[i],prime[j]);
			if(i % prime[j] == 0) break;
		}
	}
}

int solve(int x)
{
	if(isPrime[x]) return INT_MAX;
	else return x - p[x] + 1;
}

int main()
{
	int N;
	cin >> N;
	linearSieve(N);
	if(isPrime[N])
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i = N - p[N] + 1;i <= N;i++)
		ans = min(ans,solve(i));
	if(ans != INT_MAX)
		cout << ans << endl;
	else 
		cout << -1 << endl;
}
