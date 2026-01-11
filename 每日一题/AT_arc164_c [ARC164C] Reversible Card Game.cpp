#include<bits/stdc++.h>
using namespace std;

struct card
{
	long long a,b;	
	long long cha;	
	
	bool operator<(const card& other) const
	{
		return cha < other.cha;
	}
	
}c[200005];

bool cmp(card a,card b)
{
	return a.cha > b.cha;
}

int main()
{
	int n;
	long long ans = 0;
	cin >> n;
	priority_queue<card> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i].a >> c[i].b;
		c[i].cha = c[i].a - c[i].b;
	}
	sort(c + 1,c + 1 + n,cmp);
	for(int i = 1;i <= n;i++)
	{
		q.push(c[i]);
	}
	while(!q.empty())
	{
		card num = q.top();
		q.pop();
		q.push({num.b,num.a,-num.cha});
		ans += q.top().a;
		q.pop();
	}
	cout << ans << endl;
}