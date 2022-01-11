#include<bits/stdc++.h>
#define inf 0x3F3F3F3F3F3F3F3FLL
#define long long long
using namespace std;
int n;
int p[200009];
int va[200009],vb[200009],vc[200009];
long sma[200009],smb[200009],smc[200009];
long f[200009];
long mn[800009];
void add(int a,int l,int r,int p,long v)
{
	mn[a]=min(mn[a],v);
	if(l==r)
		return;
	int mid=(l+r)/2;
	if(p<=mid)
		add(a*2,l,mid,p,v);
	else
		add(a*2+1,mid+1,r,p,v);
}
long ask(int a,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll)
		return inf;
	if(l>=ll&&r<=rr)
		return mn[a];
	int mid=(l+r)/2;
	return min(ask(a*2,l,mid,ll,rr),ask(a*2+1,mid+1,r,ll,rr));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",p+i);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",va+i,vb+i,vc+i);
		vb[i]=min(vb[i],va[i]);
		vc[i]=min(vc[i],va[i]);
		sma[i]=sma[i-1]+va[i];
		smb[i]=smb[i-1]+vb[i];
		smc[i]=smc[i-1]+vc[i];
	}
	memset(mn,0x3F,sizeof(mn));
	for(int i=1;i<=n;i++)
	{
		int x=p[i];
		f[x]=smb[x-1]+smc[n]-smc[x];
		long mn=ask(1,1,n,1,x-1);
		f[x]=min(f[x],mn+sma[x-1]-smc[x]);
		add(1,1,n,x,f[x]+smc[x]-sma[x]);
	}
	long ans=inf;
	for(int i=1;i<=n;i++)
		ans=min(ans,f[i]);
	printf("%lld",ans);
	return 0;
}