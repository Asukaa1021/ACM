#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n , x ;
		long long k;
		cin >> n >> x >> k;
		deque<int> dq;
		deque<int> dq2;
		deque<int> dq3;
		vector<bool> vis(n + 3);
		if(k / n % 2 == 1)
		{
			for(int i = 1;i <= n;i++) dq.push_back(n + 1 - i);
			x = 1 - x;
		 } 
		else for(int i = 1;i <= n;i++) dq.push_back(i);
		k = k %  n;
		int i;
		i = n / 2;
		for(int u = 1;u <= k;u++)
		{
			if(x == 1)
			{
				x = 0;
				dq3.push_back(dq[i]);
				vis[i] = true;
				i += u;
			}
			else
			{
				x = 1;
				dq2.push_front(dq[i]);
				vis[i] = true;
				i -= u;
			}
		}
		if(k != 0)
		{
			for(int u = 0;u < dq2.size();u++) cout << dq2[u] << ' ';
			for(int u = 0;u < dq.size();u++)
			{
				if(!vis[u]) cout << dq[u] << ' ';
			}
			for(int u = 0;u < dq3.size();u++) cout << dq3[u] << ' ';
			
		}
		else
		{
			for(int u = 0;u < dq.size();u++) cout << dq[u] << ' ';
		}
		
		cout << endl;
	}
}