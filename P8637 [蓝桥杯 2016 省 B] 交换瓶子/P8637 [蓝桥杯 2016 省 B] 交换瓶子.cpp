#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1;i <= n;i++) cin >> a[i];
	vector<int> pos(n + 1);
	for(int i = 1;i <= n;i++)
	{
		pos[a[i]] = i;
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] == i) continue;
		int p = pos[i];
		swap(a[i],a[p]);
		swap(pos[a[i]],pos[a[p]]);
		cnt++;
	}
	cout << cnt << endl;
}
