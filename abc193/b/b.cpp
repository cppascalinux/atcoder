#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7F7F7F7F
using namespace std;
int n;
int a[100009],b[100009],c[100009];
int main()
{
	scanf("%d",&n);
	int ans=inf;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",a+i,b+i,c+i);
		c[i]-=a[i];
		if(c[i]>0)
			ans=min(ans,b[i]);
	}
	printf("%d",ans==inf?-1:ans);
	return 0;
}