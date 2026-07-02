#include<bits/stdc++.h>
using namespace std;

int n;
int tr[2000005];
int tail = 0;

void up(int x)
{
	if(x == 1) return;
	if(tr[x] >= tr[x / 2]) return;
	swap(tr[x],tr[x / 2]);
	up(x / 2);
}

void down(int x)
{
	if(x * 2 + 1 <= tail)
		if(tr[x] > tr[x * 2 + 1])
		{
			swap(tr[x] , tr[x * 2 + 1]);
			down(x * 2 + 1);
		}
	if(x * 2 <= tail)
		if(tr[x] > tr[x * 2])
		{
			swap(tr[x] , tr[x * 2]);
			down(x * 2);
		}
		
}

int main()
{
	cin >> n;
	while(n--)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			cin >> tr[++tail];
			up(tail);
		}
		else if(op == 2)
		{
			cout << tr[1] << endl;
		}
		else
		{
			swap(tr[1],tr[tail]);
			tail--;
			down(1);
		}
	}
}
