#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
struct edge
{
	int v;
	ll l;
	edge(int a,ll b):v(a),l(b){}
};
int n;
vector<edge> e[200009];
ll v[200009];
void dfs(int x,int fa,ll val)
{
	v[x]=val;
	for(edge t:e[x])
		if(t.v!=fa)
			dfs(t.v,x,val^t.l);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		ll c;
		scanf("%d%d%lld",&a,&b,&c);
		e[a].emplace_back(b,c);
		e[b].emplace_back(a,c);
	}
	dfs(1,0,0);
	int ans=0;
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d v:%lld\n",i,v[i]);
	for(int i=0;i<=60;i++)
	{
		int sm[2]={0};
		for(int j=1;j<=n;j++)
			sm[v[j]>>i&1]++;
		int rep=(ll)sm[0]*sm[1]%mod;
		ans=(ans+(1LL<<i)%mod*rep)%mod;
	}
	printf("%d",ans);
	return 0;
}