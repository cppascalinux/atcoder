#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int n;
vector<int> g[2009];
int f[2009][2009][3];
int tmp[2009][3];
int sz[2009];
void dfs(int x,int fa)
{
	sz[x]=1;
	f[x][0][0]=1;
	f[x][1][2]=1;
	for(int v:g[x])
		if(v!=fa)
		{
			dfs(v,x);
			for(int i=0;i<=sz[x]+sz[v];i++)
				memset(tmp[i],0,sizeof(tmp[i]));
			for(int i=0;i<=sz[x];i++)
				for(int j=0;j<=sz[v];j++)
				{
					tmp[i+j][0]=(tmp[i+j][0]+(ll)f[x][i][0]*(f[v][j][0]+f[v][j][1]))%mod;
					tmp[i+j][1]=(tmp[i+j][1]+f[x][i][1]*((ll)f[v][j][0]+f[v][j][1]+f[v][j][2]))%mod;
					tmp[i+j+1][1]=(tmp[i+j+1][1]+(ll)f[x][i][0]*f[v][j][2])%mod;
					tmp[i+j][2]=(tmp[i+j][2]+(ll)f[x][i][2]*(f[v][j][1]+f[v][j][2]))%mod;
					tmp[i+j+1][2]=(tmp[i+j+1][2]+(ll)f[x][i][2]*f[v][j][0])%mod;
				}
			for(int i=0;i<=sz[x]+sz[v];i++)
				memcpy(f[x][i],tmp[i],sizeof(tmp[i]));
			sz[x]+=sz[v];
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0);
	for(int i=0;i<=n;i++)
	{
		int ans=((ll)f[1][i][0]+f[1][i][1]+f[1][i][2])%mod;
		printf("%d\n",ans);
	}
	return 0;
}