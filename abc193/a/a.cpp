#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	double a,b,c;
	scanf("%lf%lf",&a,&b);
	printf("%.12lf",(a-b)/a*100);
	return 0;
}