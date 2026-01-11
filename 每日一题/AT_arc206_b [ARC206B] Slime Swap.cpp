#include<bits/stdc++.h>
using namespace std;
#define N 200005
vector<vector<int>> q;
vector<int> tail;
long long ans;
int p[N],c[N],n;
long long count(vector<int> k)
{
	tail.clear();
	for(int i = 0;i < k.size();i++)
	{
		if(i == 0) tail.push_back(k[i]);
		else
		{
			int t = tail.size() - 1;
			if(k[i] > tail[t])//大于末尾
			{
				tail.push_back(k[i]);
			}
			else
			{
				size_t pos = lower_bound(tail.begin(),tail.end(),k[i]) - tail.begin();
				tail[pos] = k[i];
			}
		}
	}
	
	long long cnt = k.size() - tail.size();
	return cnt;
}

int main()
{
	cin >> n;
	q.resize(N);
	for(int i = 1 ;i <= n;i++)	cin >> p[i];
	for(int i = 1 ;i <= n;i++)	cin >> c[i];
	
	for(int i = 1 ;i <= n;i++)	q[c[i]].push_back(p[i]);
	
	for(long long i = 1;i <= N - 3;i++)
	{
		if(q[i].size() != 0)
		{
			ans += i * count(q[i]);
		}
	}
	cout << ans <<endl;
}