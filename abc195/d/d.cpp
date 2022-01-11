#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	int w,id;
	bool operator<(const node &p)const{return w<p.w;}
};
int n,m,q;
int st[109];
int w[109],v[109];
node p[109];
int vis[109];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d%d",w+i,v+i);
	for(int i=1;i<=m;i++)
		scanf("%d",&p[i].w),p[i].id=i;
	sort(p+1,p+m+1);
	for(int i=1;i<=q;i++)
	{
		int l,r,tp=0,ans=0;
		scanf("%d%d",&l,&r);
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=m;j++)
			if(p[j].id<l||p[j].id>r)
			{
				int mp=0;
				for(int k=1;k<=n;k++)
					if(!vis[k]&&w[k]<=p[j].w&&v[k]>v[mp])
						mp=k;
				if(mp)
				{
					vis[mp]=1;
					ans+=v[mp];
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}