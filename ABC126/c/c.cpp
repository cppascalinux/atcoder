#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define db long double
using namespace std;
int n,k;
int tme[200009];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	scanf("%d%d",&n,&k);
	for(int i=k-1;i>=1;i--)
		tme[i]=tme[i*2]+1;
	db ans=0;
	for(int i=1;i<=n;i++)
		ans+=(db)1.0/(1<<tme[i]);
	printf("%.12lf",(double)(ans/n));
	return 0;
}