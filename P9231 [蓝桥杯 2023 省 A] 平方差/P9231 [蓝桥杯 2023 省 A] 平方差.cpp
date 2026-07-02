#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long L,R;
	cin >> L >> R;
	cout << R - (R + 2) / 4 - L + 1 + (L + 1) / 4 << endl;
}