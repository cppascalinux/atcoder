#include<bits/stdc++.h>
#define ll long long
using namespace std;
int m=0;
int vis[109],pm[109];
int sm[109];
ll f[2][1050009];
void init()
{
	for(int i=2;i<=72;i++)
	{
		if(!vis[i])
			pm[++m]=i;
		for(int j=1;j<=m&&i*pm[j]<=72;j++)
			vis[i*pm[j]]=1;
	}
}
int main()
{
	ll a,b;
	scanf("%lld%lld",&a,&b);
	init();
	int cur=0;
	f[0][0]=1;
	for(ll i=a;i<=b;i++)
	{
		cur^=1;
		memset(f[cur],0,sizeof(f[cur]));
		int ns=0;
		for(int j=1;j<=m;j++)
			if(i%pm[j]==0)
				ns|=1<<(j-1);
		for(int s=0;s<1<<m;s++)
		{
			f[cur][s]+=f[cur^1][s];
			if((ns&s)==0)
				f[cur][ns|s]+=f[cur^1][s];
		}
	}
	ll ans=0;
	for(int s=0;s<1<<m;s++)
		ans+=f[cur][s];
	printf("%lld",ans);
	return 0;
}