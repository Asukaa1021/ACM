#include<bits/stdc++.h>
using namespace std;
double x[105],y[105];
double dis[105][105];
inline double Dis(int a,int b)
{
	double dx = abs(x[a] - x[b]);
	double dy = abs(y[a] - y[b]);
	return sqrt(dx * dx + dy * dy);
}

inline double Dis2(int a,int b)
{
	double dx = x[a] - x[b];
	double dy = y[a] - y[b];
	return dx * dx + dy * dy;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		double t;
		int A,B,n;
		memset(dis,0,sizeof dis);
		memset(x,0,sizeof x);
		memset(y,0,sizeof y);
		vector<vector<int>> edge;

		cin >> n >> t >> A >> B;
		edge.resize(n * 5 + 1);
		for(int i = 1;i <= n;i++)
		{
			double tt;
			int num = (i - 1) * 4 + 1;
			cin >> x[num] >> y[num] >> x[num + 1] >> y[num + 1] >> x[num + 2] >> y[num + 2] >> tt;
			if(abs(Dis2(num,num + 1) + Dis2(num + 2,num + 1) - Dis2(num,num + 2)) <= 1e-6) 
			{
				x[num + 3] = x[num] + x[num + 2] - x[num + 1];
				y[num + 3] = y[num] + y[num + 2] - y[num + 1];
			}
			else if(abs(Dis2(num,num + 2) + Dis2(num + 2,num + 1) - Dis2(num,num + 1)) <= 1e-6)
			{
				x[num + 3] = x[num] + x[num + 1] - x[num + 2];
				y[num + 3] = y[num] + y[num + 1] - y[num + 2];
			}
			else
			{
				x[num + 3] = x[num + 2] + x[num + 1] - x[num];
				y[num + 3] = y[num + 2] + y[num + 1] - y[num];
			}
			for(int j = num;j <= num + 3;j++)
			{
				for(int k = num;k < j;k++)
				{
					dis[j][k] = dis[k][j] = Dis(j,k) * tt;
					edge[j].push_back(k);
					edge[k].push_back(j);
				}
			}
		}
		
		for(int i = 1;i <= n * 4;i++)
		{
			for(int j = 1;j < i;j++)
			{
				if(dis[i][j] == 0)
					dis[i][j] = dis[j][i] = Dis(j,i) * t;
				else dis[i][j] = dis[j][i] = min(Dis(j,i) * t,dis[j][i]);
				edge[j].push_back(i);
				edge[i].push_back(j);
			}
		}
		double ans = DBL_MAX;
		A = (A - 1) * 4 + 1;
		B = (B - 1) * 4 + 1;
		for(int st = A;st <= A + 3;st++)
		{
			double d[105];
			for(int i = 0;i < 105;i++) d[i] = DBL_MAX;
			d[st] = 0;
			priority_queue<pair<double,int>> pq;
			pq.push({0,st});
			while(!pq.empty())
			{
				int u = pq.top().second;
				pq.pop();
				for(auto & v : edge[u])
				{
					if(d[v] > d[u] + dis[u][v])
					{
						d[v] = dis[u][v] + d[u];
						pq.push({d[v],v});
					}
				}
			}
			ans = min({ans,d[B],d[B + 1],d[B + 2],d[B + 3]});
		}
		
		printf("%.1lf\n",ans);
	}
}
