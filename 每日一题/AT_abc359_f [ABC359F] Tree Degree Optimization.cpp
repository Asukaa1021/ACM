#include<bits/stdc++.h>
using namespace std;
#define PII pair<long long,int>
priority_queue<PII,vector<PII>,greater<PII>> pq;
long long a[200005],d[200005];
int main()
{
	int n;
	long long sum = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
		pq.push({3 * a[i],i});
		sum += a[i];
		d[i] = 1;
	}
	for(int i = 1;i <= n - 2;i++)
	{
		long long k = pq.top().first;
		int num = pq.top().second;
		pq.pop();
		
		sum += k;d[num]++;
		k = (2 * d[num] + 1) * a[num];
		
		pq.push({k,num});
		
	}
	cout << sum << endl;
}