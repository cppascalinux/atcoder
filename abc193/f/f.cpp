#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define inf 0x7F7F7F7F
using namespace std;
int n,tot=1,s,t;
char ss[109];
int mat[109][109];
int d[2][2]={{1,0},{0,1}};
int hd[10009],eg[1000009],cap[1000009],nxt[1000009];
int dep[10009],cur[10009];
void add(int a,int b,int c1,int c2)
{
	eg[++tot]=b;
	cap[tot]=c1;
	nxt[tot]=hd[a];
	hd[a]=tot;
	eg[++tot]=a;
	cap[tot]=c2;
	nxt[tot]=hd[b];
	hd[b]=tot;
}
int bfs()
{
	for(int i=1;i<=n*n+2;i++)
		dep[i]=0,cur[i]=hd[i];
	dep[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=hd[x];i;i=nxt[i])
			if(cap[i]&&!dep[eg[i]])
				dep[eg[i]]=dep[x]+1,q.push(eg[i]);
	}
	return dep[t];
}
int dfs(int x,int a)
{
	if(x==t||a==0)
		return a;
	int f,totf=0;
	for(int &i=cur[x];i;i=nxt[i])
		if(cap[i]&&dep[eg[i]]==dep[x]+1&&(f=dfs(eg[i],min(a,cap[i]))))
		{
			cap[i]-=f;
			cap[i^1]+=f;
			a-=f;
			totf+=f;
			if(!a)
				break;
		}
	return totf;
}
int flow()
{
	int totf=0;
	while(bfs())
		totf+=dfs(s,inf);
	return totf;
}
int main()
{
	scanf("%d",&n);
	s=n*n+1,t=n*n+2;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ss+1);
		for(int j=1;j<=n;j++)
			mat[i][j]=ss[j]=='B'?1:(ss[j]=='W'?0:-1);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if((i+j)&1&&mat[i][j]>=0)
				mat[i][j]^=1;
			int id=(i-1)*n+j;
			if(mat[i][j]==0)
				add(s,id,inf,0);
			else if(mat[i][j]==1)
				add(id,t,inf,0);
			for(int k=0;k<2;k++)
			{
				int nx=i+d[k][0],ny=j+d[k][1];
				int nid=(nx-1)*n+ny;
				if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
					add(id,nid,1,1);
			}
		}
	int ans=2*n*(n-1)-flow();
	printf("%d",ans);
	return 0;
}