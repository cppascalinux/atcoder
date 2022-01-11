#include<bits/stdc++.h>
using namespace std;
int n,k,mx,sm;
vector<int> g[200009];
int f[200009][2];
void dfs(int x,int fa)
{
	vector<int> vs;
	for(int v:g[x])
		if(v!=fa)
		{
			dfs(v,x);
			vs.push_back(f[v][0]+1);
		}
	sort(vs.begin(),vs.end());
	while(vs.size()>=2&&vs.back()+*(vs.end()-2)>mx)
		vs.pop_back(),sm++;
	while(vs.size()&&vs.back()>mx)
		vs.pop_back(),sm++;
	f[x][0]=f[x][1]=0;
	for(int v:vs)
	{
		if(v>f[x][0])
			f[x][1]=f[x][0],f[x][0]=v;
		else if(v>f[x][1])
			f[x][1]=v;
	}
}
int judge(int v)
{
	mx=2*v;
	sm=1;
	dfs(1,0);
	// printf("mx:%d sm:%d\n",mx,sm);
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d f0:%d f1:%d\n",i,f[i][0],f[i][1]);
	if(sm<=k)
		return 1;
	return 0;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int l=1,r=n+1;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(judge(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%d",l);
	return 0;
}