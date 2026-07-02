#include<bits/stdc++.h>
using namespace std;

struct node
{
	int l,r;
	int num;
}tr[30];

void pre(int root)
{
	cout << (char)(root + '0');
	if(tr[root].l != -1) pre(tr[root].l);
	if(tr[root].r != -1) pre(tr[root].r);
}

int main()
{
	int n;
	int rt;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		string a;
		cin >> a;
		if(i == 1) rt = a[0] - '0';
		tr[a[0] - '0'].num = a[0] - '0';
		if(a[1] != '*') tr[a[0] - '0'].l = a[1] - '0';
		else tr[a[0] - '0'].l = -1;
		if(a[2] != '*') tr[a[0] - '0'].r = a[2] - '0';
		else tr[a[0] - '0'].r = -1;
	}
	pre(rt);
	
}