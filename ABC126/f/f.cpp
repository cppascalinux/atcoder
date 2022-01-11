#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k;
int ans[1000009];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
#endif
	scanf("%d%d",&m,&k);
	if(m==1)
	{
		if(k==0)
			printf("0 0 1 1");
		else
			printf("-1");
		return 0;
	}
	n=1<<m;
	if(k>=n)
	{
		printf("-1");
		return 0;
	}
	ans[n]=k;
	int cur=0;
	for(int i=1;i<=n-1;i++)
	{
		if(cur==k)
			cur++;
		ans[i]=cur;
		cur++;
	}
	for(int i=n+1;i<=2*n-1;i++)
		ans[i]=ans[2*n-i];
	ans[2*n]=k;
	for(int i=1;i<=2*n;i++)
		printf("%d ",ans[i]);
	return 0;
}