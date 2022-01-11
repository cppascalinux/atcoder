#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a+b==2*c||a+c==2*b||b+c==2*a)
		printf("Yes");
	else
		printf("No");
	return 0;
}