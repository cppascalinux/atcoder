#include<bits/stdc++.h>
#define inf 0x3F3F3F3F
using namespace std;
struct node
{
	int u,v;
};
int n,m;
vector<int> g[1009][27];
int f[1009][1009];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		char c[5];
		scanf("%d%d%s",&a,&b,c+1);
		g[a][c[1]-'a'+1].push_back(b);
		g[b][c[1]-'a'+1].push_back(a);
	}
	memset(f,0x3F,sizeof(f));
	queue<node> q;
	for(int i=1;i<=n;i++)
		q.push(node{i,i}),f[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=26;j++)
			for(int k:g[i][j])
				if(i<k)
					q.push(node{i,k}),f[i][k]=f[k][i]=1;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(int i=1;i<=26;i++)
			for(int k:g[t.u][i])
				for(int l:g[t.v][i])
					if(f[k][l]>=inf)
					{
						f[k][l]=f[l][k]=f[t.u][t.v]+2;
						int nk=min(k,l),nl=max(k,l);
						q.push(node{nk,nl});
					}
	}
	printf("%d",f[1][n]<inf?f[1][n]:-1);
	return 0;
}