#include<bits/stdc++.h>
using namespace std;

int t;
string tg[10] = {"geng","xin","ren","gui","jia","yi","bing","ding","wu","ji"};
string dz[12] = {"zi","chou","yin","mao","chen","si","wu","wei","shen","you","xu","hai"};

int main()
{
	cin >> t;
	t += 20;
	//if(t == 0) cout << "bingshen" << endl;
	//else if(t == 1) cout << "dingyou" << endl;
	//else if(t == 2) cout << "wuxu" << endl;
	//else if(t == 3) cout << "jihai" << endl;
	//else
	cout << tg[t % 60 % 10] << dz[t % 60 % 12] << endl;

	
}
