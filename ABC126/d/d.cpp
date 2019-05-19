#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define li long long
using namespace std;
int n,tot;
int hd[100009],eg[200009],nxt[200009],len[200009];
int cl[100009];
void ins(int a,int b,int c)
{
	eg[++tot]=b;
	len[tot]=c;
	nxt[tot]=hd[a];
	hd[a]=tot;
}
void dfs(int x,int fa,li dis)
{
	if(dis&1)
		cl[x]=1;
	else
		cl[x]=0;
	for(int i=hd[x];i;i=nxt[i])
		if(eg[i]!=fa)
			dfs(eg[i],x,dis+len[i]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1,a,b,c;i<=n-1;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		ins(a,b,c);
		ins(b,a,c);
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++)
		printf("%d\n",cl[i]);
	return 0;
}