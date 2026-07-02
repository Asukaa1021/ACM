#include<bits/stdc++.h>
using namespace std;

deque<int> dq;
vector<int> num;
int n,k;
int main()
{
	cin >> n >> k;
	num.resize(n + 1);
	for(int i = 1;i <= n;i++) cin >> num[i];
	for(int i = 1;i <= n;i++)
	{
		while(!dq.empty() && num[i] < num[dq.back()]) dq.pop_back();
		dq.push_back(i);
		if(dq.front() < i - k + 1) dq.pop_front();
		if(i - k >= 0) cout << num[dq.front()] << " ";
	}
	dq.clear();
	cout << endl;
	for(int i = 1;i <= n;i++)
	{
		while(!dq.empty() && num[i] > num[dq.back()]) dq.pop_back();
		dq.push_back(i);
		if(dq.front() < i - k + 1) dq.pop_front();
		if(i - k >= 0) cout << num[dq.front()] << " ";
	}
}
