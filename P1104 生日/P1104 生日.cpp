#include<bits/stdc++.h>
using namespace std;

struct Stu
{
	string Name;
	int Year,Month,Day;	
	int Num;
}a[105];

bool cmp(Stu a,Stu b)
{
	if(a.Year==b.Year)
	{
		if(a.Month==b.Month)
		{
			if(a.Day==b.Day) return a.Num>b.Num;
			return a.Day<b.Day;
		}
		return a.Month<b.Month;
	}
	return a.Year<b.Year;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].Name>>a[i].Year>>a[i].Month>>a[i].Day;
		a[i].Num=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i].Name<<endl;
	}
	
}