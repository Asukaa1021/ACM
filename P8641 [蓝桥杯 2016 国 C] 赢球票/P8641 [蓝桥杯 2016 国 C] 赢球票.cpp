#include<bits/stdc++.h>
using namespace std;

vector<int> num(105);
vector<int> l(105),r(105);
int A = INT_MIN;
int main()
{
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> num[i];
	for(int i = 2;i < n;i++)
	{
		r[i] = i + 1;
		l[i] = i - 1;
	}
	r[n] = 1;r[1] = 2;
	l[1] = n;l[n] = n - 1;
	for(int i = 1;i <= n;i++)
	{
		vector<int> L = l,R = r;
		int pos = i;int sum = 1;
		int ans = 0;int cnt = 0;
		while(sum <= n)
		{
			if(num[pos] == sum)
			{
				R[L[pos]] = R[pos];
				L[R[pos]] = L[pos];
				ans += num[pos];
				pos = R[pos];
				sum = 1;
				if(++cnt == n) break;
			}
			else
			{
				sum++;
				pos = R[pos];
			}
		}
		A = max(A,ans);
	}
	cout << A << endl;
}