#include<bits/stdc++.h>
using namespace std;

vector<long long> preSum;
vector<long long> num;
long long sum;

int main()
{
	int n;
	cin >> n;
	long long cnt = 0;
	num.resize(n + 1);
	preSum.resize(n + 1);
	for(int i = 1;i <= n;i++)
	{
		cin >> num[i];
		sum += num[i];
		preSum[i] = preSum[i - 1] + num[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cnt += (sum - preSum[i]) * num[i];
	}
	cout << cnt << endl;
}