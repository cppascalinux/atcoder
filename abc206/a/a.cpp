#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	scanf("%d",&a);
	a*=1.08;
	if(a<206)
		printf("Yay!\n");
	else if(a==206)
		printf("so-so\n");
	else
		printf(":(\n");
	return 0;
}