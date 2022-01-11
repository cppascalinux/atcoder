#include<bits/stdc++.h>
#define ll long long
#define inf 0x3F3F3F3F3F3F3F3FLL
using namespace std;
struct node
{
	int v,a,b,id;
	node(){}
	node(int x,int y,int z,int w):v(x),a(y),b(z),id(w){}
	bool operator<(const node &p)const{return a<p.a;}
};
struct edge
{
	int v;
	ll l;
	edge(){}
	edge(int a,ll b):v(a),l(b){}
	bool operator<(const edge &p)const{return l>p.l;}
};
int n,m,tot;
vector<node> k0[100009],rk0[100009];
vector<edge> g[500009];
int vis[500009];
ll dis[500009];
template<class T>
void clr(vector<T> &s)
{
	vector<T> tmp;
	tmp.swap(s);
}
void dij()
{
	priority_queue<edge> pq;
	for(int i=1;i<=tot;i++)
	{
		vis[i]=0;
		dis[i]=inf;
	}
	dis[1]=0;
	pq.push(edge(1,0));
	while(!pq.empty())
	{
		edge t=pq.top();
		pq.pop();
		vis[t.v]=1;
		for(edge u:g[t.v])
			if(!vis[u.v]&&dis[u.v]>t.l+u.l)
			{
				dis[u.v]=t.l+u.l;
				pq.push(edge(u.v,dis[u.v]));
			}
	}
	for(int i=1;i<=n;i++)
	{
		for(node t:rk0[i])
			dis[i]=min(dis[i],dis[t.id]);
	}
	for(int i=1;i<=n;i++)
		printf("%lld%c",dis[i]<inf?dis[i]:-1,i==n?'\n':' ');
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			// clr(k0[i]);
			// clr(rk0[i]);
			k0[i].clear();
			rk0[i].clear();
		}
		for(int i=1;i<=n+2*m+1;i++)
		{
			// clr(g[i]);
			g[i].clear();
		}
		tot=n;
		if(tot%2==0)
			tot++;
		for(int i=1;i<=m;i++)
		{
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			k0[a].emplace_back(b,c,d,++tot);
			rk0[b].emplace_back(a,c,d,++tot);
			g[a].emplace_back(b,c);
		}
		for(int i=1;i<=n;i++)
		{
			int szi=rk0[i].size();
			int szo=k0[i].size();
			sort(k0[i].begin(),k0[i].end());
			for(int j=0;j<szo;j++)
			{
				int d=k0[i][j].id;
				g[d].emplace_back(k0[i][j].v,k0[i][j].a-k0[i][j].b);
				g[d].emplace_back(d^1,k0[i][j].a-k0[i][j].b);
				g[i].emplace_back(d^1,k0[i][j].a);
			}
			for(int j=1;j<szo;j++)
				g[k0[i][j-1].id].emplace_back(k0[i][j].id,0);
			for(int j=0;j<szi;j++)
			{
				int vl=rk0[i][j].a;
				int p=upper_bound(k0[i].begin(),k0[i].end(),node(0,vl,0,0))-k0[i].begin();
				// int p=0;
				if(p>=szo)
					continue;
				// printf("i:%d j:%d vl:%d vo:%d\n",i,j,vl,k0[i][p].a);
				// fflush(stdout);
				g[rk0[i][j].id].emplace_back(k0[i][p].id,0);
			}
		}
		dij();
	}
	return 0;
}