#include<bits/stdc++.h>
using namespace std;
int cB = 0,cA = 0,cT = 0;
int ans = INT_MAX;	string s;
void solve1()//B在前
{
	int cc = 0,A = 0,T = 0;
	for(int i = 0;i < cB;i++)
	{
		if(s[i] != 'B') cc++;
		if(s[i] == 'A') A++;
	}
	T = cc - A;
	int AB = 0,AT = 0;
	for(int i = cB;i < cB + cA;i++)//a
	{
		if(s[i] == 'B') AB++;
		if(s[i] == 'T') AT++;
	}
	ans = min(ans,cc + AT + max(0,AB - A));
	int TB = 0,TA = 0;
	for(int i = cB;i < cB + cT;i++)//T
	{
		if(s[i] == 'B') TB++;
		if(s[i] == 'A') TA++;
	}
	ans = min(ans,cc + TA + max(0,TB - T));
}
void solve2()//T
{
	int cc = 0,A = 0,B = 0;
	for(int i = 0;i < cT;i++)
	{
		if(s[i] != 'T') cc++;
		if(s[i] == 'A') A++;
	}
	B = cc - A;
	int AB = 0,AT = 0;
	for(int i = cT;i < cT + cA;i++)//a
	{
		if(s[i] == 'B') AB++;
		if(s[i] == 'T') AT++;
	}
	ans = min(ans,cc + AB + max(0,AT - A));
	int BA = 0,BT = 0;
	for(int i = cT;i < cT + cB;i++)//b
	{
		if(s[i] == 'A') BA++;
		if(s[i] == 'T') BT++;
	}
	ans = min(ans,cc + BA + max(0,BT - B));
}
void solve3()//A
{
	int cc = 0,B = 0,T = 0;
	for(int i = 0;i < cA;i++)
	{
		if(s[i] != 'A') cc++;
		if(s[i] == 'B') B++;
	}
	T = cc - B;
	int BA = 0,BT = 0;
	for(int i = cA;i < cA + cB;i++)//b
	{
		if(s[i] == 'A') BA++;
		if(s[i] == 'T') BT++;
	}
	ans = min(ans,cc + BT + max(0,BA - B));
	int TA = 0,TB = 0;
	for(int i = cA;i < cA + cT;i++)//T
	{
		if(s[i] == 'B') TB++;
		if(s[i] == 'A') TA++;
	}
	ans = min(ans,cc + TB + max(0,TA - T));
}
int main()
{

	cin >> s;
	
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] == 'B') cB++;
		if(s[i] == 'A') cA++;
		if(s[i] == 'T') cT++;
	}
	solve1();
	solve2();
	solve3();
	cout << ans << endl;
}