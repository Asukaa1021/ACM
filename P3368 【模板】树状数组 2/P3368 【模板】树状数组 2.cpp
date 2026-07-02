#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> cf;
vector<int> tr;
vector<int> a;

int lowBit(int x)
{
	return x & -x;
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
	while(x)
	{
		ans += tr[x];
		x -= lowBit(x);
	}
	return ans;
}

int main()
{
	cin >> n >> m;
	cf.resize(n + 1);
	tr.resize(n + 1);
	a.resize(n + 1);
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cf[i] = a[i] - a[i - 1];
	}
	for(int i = 1;i <= n;i++)
	{
		change(i,cf[i]);
	//	change(i + 1,-cf[i]);
	}
	while(m--)
	{
		int op,x,y;
		cin >> op;
		if(op == 1)
		{
			int x,y,k;
			cin >> x >> y >> k;
			change(x,k);
			change(y + 1,-k);
		}
		else 
		{
			int x;
			cin >> x;
			cout << query(x) << endl;
		}
	}
}