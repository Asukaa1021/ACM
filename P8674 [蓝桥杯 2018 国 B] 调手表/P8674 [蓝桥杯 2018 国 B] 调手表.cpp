#include<bits/stdc++.h>
using namespace std;

vector<long long> num(100005);
vector<bool> vis(100005);
int main()
{
	int n,k;
	cin >> n >> k;
	for(int i = 1;i < n;i++) num[i] = i;
	int st = 0;
	long long cnt1 = 1,cnt2;
	while(!vis[st + k])
	{
		vis[st + k] = true;
		for(int i = st + k;i < n;i += k,cnt1++)
		{
			cnt2 = cnt1;
			for(int j = i;j < i + k && j < n;j++,cnt2++)
			{
				if(cnt2 >= num[j]) break;
				num[j] = cnt2;
			}
			st = i - n;
		}
	}
//	for(int i = 1;i < n;i++) cout << num[i] << ' ';
//	cout << endl;
	sort(num.begin() + 1,num.begin() + n);
	cout << num[n - 1] << endl;
}