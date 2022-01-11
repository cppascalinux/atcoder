#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=1000000;i++)
		if((n-=i)<=0)
			return printf("%d\n",i),0;
	return 0;
}