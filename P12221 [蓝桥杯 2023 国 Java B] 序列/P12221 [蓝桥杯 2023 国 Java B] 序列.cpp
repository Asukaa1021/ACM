#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int> num;
int cnt;

int gcd_(int a,int b)
{
	if(a < b) swap(a,b);
	if(a % b == 0) return b;
	return gcd_(b,a % b);
}

signed main()
{
	cin >> n;
	num.resize(n + 1);
	for(int i = 1;i <= n;i++) cin >> num[i];
	
	for(int i = 1;i <= n;i++)
	{
		//if(i % num[i] == 0) cnt += n;
	//	else
		//{
			int a = num[i] / gcd_(i,num[i]);
			cnt += n / a;
	//	}
	}
	cout << cnt << endl;
}
