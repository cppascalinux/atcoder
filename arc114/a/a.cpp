#include<bits/stdc++.h>
#define ll long long
#define i128 __int128
using namespace std;
int n,m;
int s[60];
int vis[60],pm[20];
void init()
{
	for(int i=2;i<=50;i++)
	{
		if(!vis[i])
			pm[++m]=i;
		for(int j=1;j<=m&&i*pm[j]<=50;j++)
			vis[i*pm[j]]=1;
	}
}
void output(i128 x)
{
	if(!x)
		return;
	output(x/10);
	printf("%d",x%10);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	init();
	i128 ans=1;
	for(int i=1;i<=m;i++)
		ans*=pm[i];
	for(int t=0;t<1<<m;t++)
	{
		for(int i=1;i<=n;i++)
			vis[i]=0;
		i128 sm=1;
		for(int i=1;i<=m;i++)
			if(t>>(i-1)&1)
			{
				sm*=pm[i];
				for(int j=1;j<=n;j++)
					if(s[j]%pm[i]==0)
						vis[j]=1;
			}
		int fg=1;
		for(int i=1;i<=n;i++)
			if(!vis[i])
				fg=0;
		if(fg&&sm<ans)
			ans=sm;
	}
	output(ans);
	return 0;
}