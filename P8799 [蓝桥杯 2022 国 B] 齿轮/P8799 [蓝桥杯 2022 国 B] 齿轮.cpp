#include<bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e5 + 5;
int n,m;
long long num[N];
long long arr[N];
bool pd[N];

int main()
{
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++)
	{
		cin >> num[i];
		arr[num[i]]++;
		if(arr[num[i]] == 2) pd[1] = true;
	}
	sort(num + 1,num + n + 1);
	for(int i = 1;i <= n;i++)
	{
		if(i != 1 && num[i] == num[i - 1]) continue;
		for(int j = num[i] * 2;j <= num[n];j += num[i])
		{
			if(pd[j / num[i]]) continue;
			if(arr[j]) pd[j / num[i]] = true;
		}
	}
	while(m--)
	{
		long long k;
		cin >> k;
		if(k > num[n] || k <= 0) cout << "NO" << endl;
		else
		{
			if(pd[k]) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	
}