#include<bits/stdc++.h>
using namespace std;

struct node
{
	long long a,b;
}num[1005];

int main()
{
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		long long a1,a2,a3;
		cin >> a1 >> a2 >> a3;
		num[i].a = a1 + a2;
		num[i].b = a3;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j < n;j++)
		{
			long long sum1 = num[j].a * (n - j + 1) + num[j].b * (n - j);
			sum1 += num[j + 1].a * (n - j) + num[j + 1].b * (n - j - 1);
			long long sum2 = num[j + 1].a * (n - j + 1) + num[j + 1].b * (n - j);
			sum2 += num[j].a * (n - j) + num[j].b * (n - j - 1);
			if(sum2 < sum1)
			{
				swap(num[j],num[j + 1]);
			}
		}
	}
	long long sum = 0;
	for(int i = 1;i <= n;i++)
	{
		sum += num[i].a * (n - i + 1);
		sum += num[i].b * (n - i);
	}
	cout << sum << endl;
}