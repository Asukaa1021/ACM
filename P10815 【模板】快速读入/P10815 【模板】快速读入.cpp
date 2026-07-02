#include<bits/stdc++.h>
long long sum = 0,n;

inline long long read(void)
{
	long long s = 0,w = 1;
	char ch = _getchar_nolock();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') w = -1;
		ch = _getchar_nolock();
	}
	while(ch >= '0' && ch <= '9') 
	{
		s = (s << 3) + (s << 1) + (ch ^ 48);
		ch = _getchar_nolock();
	}
	return s * w;
}

int main()
{
	n = read();
	for(long long i = 1;i <= n;i++)
	{
		long long k;
		k = read();
		sum += k;
	}
	printf("%lld\n",sum);
}