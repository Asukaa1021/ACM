#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> q(n + 1);
vector<int> tr(n + 1);

int lowBit(int x)
{
	return (x & -x);
}

void change(int x,int k)
{
	while(x <= n)
	{
		tr[x] += k;
		x += lowBit(x);
	}
}

int query(int x)
{
	int ans = 0;
	while(x >= 1)
	{
		ans += tr[x];
		x -= lowBit(x);
	}
	return ans;
}

int main()
{

	cin >> n >> m;
	q.resize(n + 1);
	tr.resize(n + 1);
	for(int i = 1;i <= n;i++)
	{
		cin >> q[i];
		change(i,q[i]);
	 } 
	while(m--)
	{
		int op,a,b;
		cin >> op >> a >> b;
		if(op == 1)
		{
			change(a,b);
		}
		else 
		{
			cout << query(b) - query(a - 1) << endl;
		}
	}
}