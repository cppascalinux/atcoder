#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x7F7F7F7F7F7F7F7FLL
#define ninf 0x8080808080808080LL
using namespace std;
int n;
ll x,ans=inf;
int s[109];
ll f[109][109];
int main()
{
	scanf("%d%lld",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	for(int i=1;i<=n;i++)//use i items
	{
		memset(f,0x80,sizeof(f));
		f[0][0]=0;
		for(int j=1;j<=n;j++)//try the jth item
		{
			for(int k=i;k>=1;k--)//k already used
			{
				for(int l=0;l<i;l++)//sum mod i==l
				{
					int ls=((l-s[j])%i+i)%i;
					f[k][l]=max(f[k][l],f[k-1][ls]+s[j]);
				}
			}
		}
		int rv=x%i;
		// for(int j=0;j<i;j++)
		// 	printf("i:%d j:%d f:%lld\n",i,j,f[i][j]);
		if(f[i][rv]>=0)
			ans=min(ans,(x-f[i][rv])/i);
	}
	printf("%lld",ans);
	return 0;
}