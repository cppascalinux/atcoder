#include<bits/stdc++.h>
#define db double
#define pi 3.14159265358979323846
using namespace std;
int main()
{
	int n;
	db x0,y0,xm,ym;
	scanf("%d",&n);
	scanf("%lf%lf%lf%lf",&x0,&y0,&xm,&ym);
	db xn=(x0+xm)/2,yn=(y0+ym)/2;
	db dx=x0-xn,dy=y0-yn;
	db cs=cos(2*pi/n),sn=sin(2*pi/n);
	db qx=dx*cs-dy*sn,qy=dx*sn+dy*cs;
	printf("%.12lf %.12lf",xn+qx,yn+qy);
	return 0;
}