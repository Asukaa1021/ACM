#include<bits/stdc++.h>
using namespace std;
#define int long long
int k[10],p[10];
int cnt;
int n1,n2,n,m;

int ksm(int d,int z)
{
	if(z == 0) return 1;
	if(z % 2 == 0) return ksm(d * d,z / 2);
	return d * ksm(d * d,z / 2);
}

void trav(vector<int>& s,int cnt,int st,int ed,int sum)
{
	if(cnt + st > ed)
	{
		s.push_back(sum);
		return;
	}
	int kk = k[cnt + st],pp = p[cnt + st];
	for(int i = 1;i <= m;i++)
	{
		sum += kk * ksm(i,pp);
		trav(s,cnt + 1,st,ed,sum);
		sum -= kk * ksm(i,pp);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> k[i] >> p[i];
	
	n1 = n / 2;
	vector<int> ans1,ans2;
	trav(ans1,1,0,n1,0);
	trav(ans2,1,n / 2,n,0);
	sort(ans2.begin(),ans2.end());
	for(auto & x : ans1)
	{
		int pos1 = lower_bound(ans2.begin(),ans2.end(),-x) - ans2.begin();
		int pos2 = lower_bound(ans2.begin(),ans2.end(),(-x + 1)) - ans2.begin();
		if(pos1 != ans2.size() && ans2[pos1] == -x)
		{
			pos2--;
			cnt += pos2 - pos1 + 1;
		}
	}
	cout << cnt << endl;
}
