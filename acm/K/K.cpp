#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
int n;
int vl[100009];
vector<int> g[100009];
vector<int> sq[100009];
int f[100009],ad[100009];
int ans[100009];
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
void clr(vector<int> &s)
{
	vector<int> tmp;
	tmp.swap(s);
}
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			clr(g[i]);
			f[i]=0;
			clr(sq[i]);
			sq[i].push_back(i);
			ad[i]=ans[i]=0;
		}
		for(int i=1;i<=n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
			// printf("a:%d b:%d\n",a,b);
		}
		map<int,int> mp;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&vl[i]);
			mp[vl[i]]=i;
		}
		for(pii t:mp)
		{
			// printf("fi:%d se:%d\n",t.fi,t.se);
			int x=t.se;
			f[x]=x;
			int y=x,ms=-1;
			for(int v:g[x])
				if(fnd(v)&&(int)sq[fnd(v)].size()>ms)
					ms=sq[fnd(v)].size(),y=v;
			int ty=fnd(y);
			// printf("x:%d y:%d\n",x,y);
			for(int v:g[x])
			{
				if(fnd(v)&&fnd(v)!=ty)
				{
					// printf("x:%d y:%d v:%d\n",x,y,v);
					int tv=fnd(v);
					for(int p:sq[tv])
					{
						ans[p]+=ad[tv];
						ans[p]-=ad[ty];
						sq[ty].push_back(p);
					}
					f[tv]=ty;
				}
			}
			if(ty!=x)
			{
				sq[ty].push_back(x);
				f[x]=ty;
			}
			ans[x]-=ad[ty];
			ad[ty]++;
			// for(int i=1;i<=n;i++)
			// 	printf("i:%d f:%d ad:%d ans:%d\n",i,fnd(i),ad[i],ans[i]);
		}
		int ft=fnd(1);
		for(int i=1;i<=n;i++)
			ans[i]+=ad[ft];
		for(int i=1;i<=n;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}