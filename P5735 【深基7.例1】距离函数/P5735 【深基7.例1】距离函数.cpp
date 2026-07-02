#include<bits/stdc++.h>
using namespace std;

float F(float a,float b,float c,float d)
{
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

int main()
{
	float x1,x2,x3,y1,y2,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	float c=F(x1,y1,x2,y2)+F(x2,y2,x3,y3)+F(x1,y1,x3,y3);
	printf("%.2f",c);
	
	return 0;
}