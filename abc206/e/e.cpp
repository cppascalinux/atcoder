#include<bits/stdc++.h>
#define ll long long
using namespace std;
int l,r;
int vis[1000009],pm[1000009];
int phi[1000009];
int d[1000009];
vector<int> v[1000009];
void init()
{
	int m=1000000,tot=0;
	for(int i=2;i<=m;i++)
	{
		if(!vis[i])
		{
			pm[++tot]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=tot&&i*pm[j]<=m;j++)
		{
			vis[i*pm[j]]=1;
			if(i%pm[j]==0)
			{
				phi[i*pm[j]]=phi[i]*pm[j];
				break;
			}
			else
				phi[i*pm[j]]=phi[i]*(pm[j]-1);
		}
	}
	for(int i=max(l,2);i<=m;i++)
		for(int j=i;j<=m;j+=i)
			d[j]++;
	for(int i=1;i<=tot;i++)
		for(int j=pm[i];j<=m;j+=pm[i])
			v[j].push_back(pm[i]);
}
int main()
{
	scanf("%d%d",&l,&r);
	init();
	ll ans=0;
	for(int i=l;i<=r;i++)
	{
		// printf("i:%d phi:%d d:%d\n",i,phi[i],d[i]);
		int t=v[i].size();
		// printf("t:%d\n",t);
		for(int s=1;s<(1<<t);s++)
		{
			int mul=-1,ps=1;
			for(int j=0;j<t;j++)
			{
				ps*=(s>>j)&1?v[i][j]:1;
				mul*=(s>>j)&1?-1:1;
			}
			ans+=mul*(i/ps-(l-1)/ps);
		}
		// printf("ans:%lld\n",ans);
		ans-=d[i];
	}
	ans*=2;
	printf("%lld",ans);
	return 0;
}