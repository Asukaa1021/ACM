#include<bits/stdc++.h>
using namespace std;

vector<long long> num(40);
long long Sum = 0,ans = LLONG_MAX;

int main()
{
	for(int i = 0;i < 40;i++)
	{
		cin >> num[i];
		Sum += num[i];
	} 
	long long sum = Sum / 2;
	vector<long long> l(1 << 20),r(1 << 20);
	for(int k = 0;k < (1 << 20);k++)
	{
		long long s = 0;
		for(int i = 0;i < 20;i++)
		{
			if(k & (1 << i)) s += num[i];
		}
		l[k] = s;
	}
	for(int k = 0;k < (1 << 20);k++)
	{
		long long s = 0;
		for(int i = 0;i < 20;i++)
		{
			if(k & (1 << i)) s += num[i + 20];
		}
		r[k] = s;
	}
	sort(l.begin(),l.end());
	sort(r.begin(),r.end());
	int ll = 0,rr = r.size() - 1;
	long long t,mi = LLONG_MAX;
	while(ll < l.size() && rr >= 0)
	{
		t = l[ll] + r[rr];
		mi = min(mi,abs(Sum - 2 * t));
		if(t < sum) ll++;
		else if(t > sum) rr--;
		else break;
	}
	cout << mi << endl;
}