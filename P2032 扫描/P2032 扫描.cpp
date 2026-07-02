#include<bits/stdc++.h>
using namespace std;

int n,k;

int main()
{
	cin >> n >> k;
	vector<int> num(n + 1);
	for(int i = 1;i <= n;i++) cin >> num[i];
	deque<int> dq;
	for(int i = 1;i <= n;i++)
	{
		if(!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
		while(!dq.empty() && num[dq.back()] < num[i]) dq.pop_back();
		dq.push_back(i);
		if(i >= k) cout << num[dq.front()] << endl;
	}
}
