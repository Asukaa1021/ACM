#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int l,c,vMax,cnt;
int v[100005],_l[100005],rest[100005],t;
int temp[100005];
int MergeSort(int l,int r)
{
	int ans = 0;
	if(l >= r) return 0;
	int mid = l + r >> 1;
	ans += MergeSort(l,mid);
	ans += MergeSort(mid + 1,r);
	
	for(int i = l;i <= mid;i++) temp[i] = rest[i];
	for(int i = mid + 1,j = r;i <= r && j >= mid + 1;i++,j--) temp[i] = rest[j];

	int x = l,y = r;
	for(int i = l;i <= r;i++)
	{
		if(temp[x] <= temp[y])
		{
			rest[i] = temp[x];
			x++;
		}
		else
		{
			rest[i] = temp[y];
			y--;
			ans += mid - x + 1;
		}
	}
	return ans;
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> l >> c;
	for(int i = 1;i <= n;i++) cin >> v[i];
	sort(v + 1,v + 1 + n);
	for(int i = 1;i <= n;i++)
	{
		_l[i] = l * v[i] / v[n];
		rest[i] = l * v[i] % v[n];
	}
	for(int i = 1;i <= n;i++)
	{
		cnt += _l[i] * (i - 1) - t;
		t += _l[i];
	} 
	cnt -= MergeSort(1,n);
	cout << cnt << endl;
}
