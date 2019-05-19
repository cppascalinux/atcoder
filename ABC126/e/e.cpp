#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,tot;
int hd[100009],eg[200009],nxt[200009];
int vis[100009];
void ins(int a,int b)
{
	eg[++tot]=b;
	nxt[tot]=hd[a];
	hd[a]=tot;
}
void dfs(int x)
{
	if(vis[x])
		return;
	vis[x]=1;
	for(int i=hd[x];i;i=nxt[i])
		dfs(eg[i]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1,a,b,c;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		ins(a,b);
		ins(b,a);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			dfs(i);
			ans++;
		}
	printf("%d",ans);
	return 0;
}