#include<bits/stdc++.h>
using namespace std;
int n,m;
long long k;
struct Node
{
	long long num;
	int zb;
}a[200005];
long long c[200005];
long long Z[200006];
long long sum;
long long b[200005];
long long preSum[200005];
bool cmp(Node a,Node b)
{
	return a.num < b.num;
}

bool check(long long x,long long z,int i)// x 是 再次投票数  z 是原有票数
{	
	if(m>=n-1) return true;
	long long les = k - sum - x;
	long long s = x + z;
	long long p = upper_bound(c+1,c+1+n,s) - c;
	p--;
	long long cnt = m - (n - p);
	if(cnt < 0) return false;
	long long ksum = 0;
	long long be = p - cnt + 1 ;
	long long extra = 0;
	if(Z[i] >= be) extra = a[Z[i]].num,be--;
	ksum =(s + 1)*(cnt) - (preSum[p] - preSum[be - 1] - extra);
	ksum--;
	if(ksum >= les) return true;
	else return false;
}

int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].num;
		a[i].zb = i;
		b[i] = a[i].num;
		c[i] = a[i].num;
		sum += a[i].num;
	}
	sort(a+1,a+1+n,cmp);
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++)
	{
		preSum[i]+=preSum[i-1] + a[i].num;
		Z[a[i].zb] = i;
	}
	for(int i=1;i<=n;i++)
	{
		long long l = 0,r = k - sum;
		long long ans = -1;
		while(l<=r)
		{
			long long mid = l + (r-l)/2;
			if(check(mid,b[i],i))
			{
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans << " ";
	}
}