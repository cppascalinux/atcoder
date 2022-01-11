#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 0x7F7F7F7F7F7F7F7FLL
#define ll long long
using namespace std;
int n,m,s,t;
int vis[100009];
ll dis[100009];
struct edge
{
	int v,l,k;
};
struct node
{
	int v;
	ll d;
	bool operator<(const node &p)const{return d>p.d;}
};
vector<edge> g[100009];
void dij()
{
	memset(dis,0x7F,sizeof(dis));
	priority_queue<node> pq;
	dis[s]=0;
	pq.push(node{s,0});
	while(!pq.empty())
	{
		node x=pq.top();
		pq.pop();
		if(vis[x.v])
			continue;
		vis[x.v]=1;
		for(edge t:g[x.v])
			if(!vis[t.v])
			{
				ll rep=x.d==0?0:(x.d-1)/t.k+1;
				ll nd=rep*t.k+t.l;
				if(nd<dis[t.v])
					dis[t.v]=nd,pq.push(node{t.v,nd});
			}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		g[a].push_back(edge{b,c,d});
		g[b].push_back(edge{a,c,d});
	}
	dij();
	// for(int i=1;i<=n;i++)
	// 	printf("%lld ",dis[i]);
	// printf("\n");
	printf("%lld",dis[t]<inf?dis[t]:-1);
	return 0;
}