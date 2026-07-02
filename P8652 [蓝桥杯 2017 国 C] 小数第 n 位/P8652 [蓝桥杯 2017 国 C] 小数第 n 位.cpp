#include<bits/stdc++.h>
using namespace std;
#define int __int128
int modd;
int ksm(int d,int z)
{
	if(z == 0) return 1;
	if(z % 2 == 0) return ksm(d * d % modd,z / 2) % modd;
	else return ksm(d * d % modd,z / 2) % modd * d % modd;
}
int read()
{
	int s = 0;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch))
	{
		s = 10 * s + ch - '0';
		ch = getchar();
	}
	return s;
}
void print(int x)
{
	char ch = x % 10 + '0';
	cout << ch;
}

signed main()
{
	int a,b,n;
	a = read();
	b = read();
	n = read();
	modd = b * 10;
	print(ksm(10,n) % modd * a % modd / b);
	print(ksm(10,n + 1) % modd * a % modd / b);
	print(ksm(10,n + 2) % modd * a % modd / b);
}