#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int st[1000005];
class stk
{
	private:
		
		int len = 0;
	
	public:
		void push(int x)
		{
			len++;
			st[len] = x;
		}
		void query()
		{
			if(len == 0) cout << "Anguei!" << endl;
			else cout << st[len] << endl;
		}
		void pop()
		{
			if(len == 0) cout << "Empty" << endl;
			else len--;
		}
		void size()
		{
			cout << len << endl;
		}
};


void solve()
{
	int n;
	stk s;
	cin >> n;
	while(n--)
	{
		string op;
		cin >> op;
		if(op == "push")
		{
			int x;
			cin >> x;
			s.push(x);
		}
		else if(op == "query")
		{
			s.query();
		}
		else if(op == "pop")
		{
			s.pop();
		}
		else
		{
			s.size();
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	 } 
}
