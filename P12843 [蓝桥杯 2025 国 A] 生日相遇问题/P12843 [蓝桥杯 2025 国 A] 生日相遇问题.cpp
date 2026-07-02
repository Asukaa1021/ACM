#include<bits/stdc++.h>
using namespace std;

int m1,d1,m2,d2,k;
int monthLen[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isRunYear(int x)
{
	if((x % 4 == 0 && x % 100 != 0) || x % 400 == 0) return true;
	else return false;
}

bool pd(int m1,int d1,int m2,int d2,int year)
{
	if(m1 == 2 && d1 == 29 && !isRunYear(year)) d1 = 28;
	if(m2 == 2 && d2 == 29 && !isRunYear(year)) d2 = 28;
	if(isRunYear(year)) monthLen[2]++;
	int day1 = 0,day2 = 0;
	for(int i = 1;i < m1;i++)
		day1 += monthLen[i];
	day1 += d1;
	for(int i = 1;i < m2;i++)
		day2 += monthLen[i];
	day2 += d2;
	if(isRunYear(year)) monthLen[2]--;
	if(abs(day1 - day2) % 7 == 0) return true;
	else return false;
}

int main()
{
	cin >> m1 >> d1 >> m2 >> d2 >> k;
	int cnt = 0;
	for(int i = 2025;i < 2025 + k;i++)
	{
		if(pd(m1,d1,m2,d2,i))
		{
			cout << i << '\n';
			cnt++;
		}		
	}
	if(cnt==0) cout << "No Answer"	<<endl;

}
