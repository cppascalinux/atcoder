#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n;
ll s[3009];
int f[3009][3009];
int md[3009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",s+i),s[i]+=s[i-1];
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		memset(md,0,sizeof(md));
		if(i==1)
			md[0]=1;
		for(int j=1;j<=n;j++)
		{
			int a=s[j]%i;
			f[i][j]=md[a];
			(md[a]+=f[i-1][j])%=mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		(ans+=f[i][n])%=mod;
	printf("%d",ans);
	return 0;
}