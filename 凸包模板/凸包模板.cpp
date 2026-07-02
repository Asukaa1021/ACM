#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Point
{
	int x = 0,y = 0;
	Point(int x,int y) : x(x),y(y) {}
	Point(){}
	bool operator < (const Point & p) const
	{
		return (x != p.x) ? x < p.x : y < p.y;
	}
	Point operator - (const Point & p) const 
	{
		return Point(x - p.x,y - p.y);
	}
};

long long cross(Point a,Point b)
{
	return a.x * b.y - a.y * b.x;
}

vector<Point> convexHull(vector<Point> &p)
{
	int n = p.size();
	if(n <= 1) return p;
	sort(p.begin(),p.end());
	vector<Point> hull(n * 2);
	int k = 0;
	for(int i = 0;i < n;i++)
	{
		while(k >= 2 && cross(hull[k - 1] - hull[k - 2] , p[i] - hull[k - 2]) <= 0) k--;
		hull[k++] = p[i];
	}
	for(int i = n - 2,t = k + 1;i >= 0;i--)
	{
		while(k >= t && cross(hull[k - 1] - hull[k - 2] , p[i] - hull[k - 2]) <= 0) k--;
		hull[k++] = p[i];
	}
	hull.resize(k - 1);
	return hull;
}

signed main()
{
	int m;
	long double r;
	cin >> m >> r;
	vector<Point> p(m);
	for(int i = 0;i < m;i++)
	{
		cin >> p[i].x >> p[i].y;
	}
	p.push_back({0,0});
	vector<Point> k = convexHull(p);
	long double ans = 0;
	for(int i = 0;i < k.size();i++)
	{
		Point p1 = k[i];
		Point p2 = (i == k.size() - 1) ? k[0] : k[i + 1];
		long double x1 = (long double)p1.x,x2 = (long double)p2.x;
		long double y1 = (long double)p1.y,y2 = (long double)p2.y;
		long double len = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		len = sqrt(len);
		long double h = abs(cross(p1 - Point(0,0),p2 - Point(0,0)) / len);
		
		long double xian = sqrt(r * r - h * h);
		xian *= 2.0;
		long double sita = acos(h / r);
		long double s = r * r * sita - xian * h / 2;
		long double ss = acos(-1) * r * r;
		ans = max(ans,min(ss - s,s));
	}
	if(m == 1)
	{
		cout << fixed  << setprecision(12) << acos(-1) * r * r / 2 << '\n';
	}
	else cout << fixed  << setprecision(12) << ans << '\n';
}
