#include<bits/stdc++.h>
using namespace std;
int stu[100005][4];
long long sum = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
	while(t--)
	{
		sum = 0;
		vector<int> cnt(4,0);
		vector<vector<int>> rec(4);
		int n;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> stu[i][1] >> stu[i][2] >> stu[i][3];
		}
		for(int i = 1;i <= n;i++)
		{
			int best;
			if(stu[i][1] >= stu[i][2] && stu[i][1] >= stu[i][3]) best = 1;
			else if(stu[i][2] >= stu[i][3] &&stu[i][2] >= stu[i][1]) best = 2;
			else best = 3;
			sum += stu[i][best];
			cnt[best]++;
			rec[best].push_back(i);
		}
		
		
		vector<int> loss_;
		int k = 0;//一定要初始化
		for(int i = 1;i <= 3;i++)
		{
			if(cnt[i] > n/2)//如果超出n/2
			{
				k = cnt[i] - n/2;//超出人数
				for(int j = 0;j < cnt[i];j++)
				{
					int loss = INT_MAX;
					int x = rec[i][j];//第几个 stu
					for(int u = 1;u <= 3;u++)
					{
						if (u == i) continue;
						loss = min(stu[x][i] - stu[x][u] , loss);//记录返回后亏损
					}
					loss_.push_back(loss);
				}
			}
		}
		sort(loss_.begin(),loss_.end());//排序  好选择最小的几个进行反悔
		for(int i = 0;i <= k - 1;i++) sum -= loss_[i];//有几个不符合  就减去最小的几个
		cout << sum <<endl;
	}
}