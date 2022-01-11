#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int f[100009],sz[100009];
vector<int> g[100009];
bool cmp(int a,int b)
{
	return f[a]>f[b];
}
void dfs(int x)
{
	sz[x]=1;
	vector<int> vs;
	f[x]=-1;
	int ts=0;
	for(int v:g[x])
	{
		dfs(v);
		sz[x]+=sz[v];
		if(sz[v]&1)
			vs.push_back(v);
		else if(f[v]>=0)
			f[x]+=f[v];
		else
			ts+=f[v];
	}
	sort(vs.begin(),vs.end(),cmp);
	for(int i=0;i<vs.size();i+=2)
		f[x]+=f[vs[i]];
	for(int i=1;i<vs.size();i+=2)
		f[x]-=f[vs[i]];
	if(vs.size()&1)
		f[x]-=ts;
	else
		f[x]+=ts;
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		g[a].push_back(i);
	}
	dfs(1);
	int ans=(n-f[1])/2;
	printf("%d",ans);
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d f:%d\n",i,f[i]);
	return 0;
}