#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct pt
{
	ll x,y;
	pt():x(0),y(0){}
	pt(ll a,ll b):x(a),y(b){}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ll operator^(pt p){return x*p.y-y*p.x;}
};
int n,m,p;
int d[100009];
int h[50009],t[50009];
pt st[50009];
ll f[109][50009];
ll cross(pt a,pt b,pt c)
{
	return (b-a)^(c-a);
}
int main()
{
	int tst;
	scanf("%d",&tst);
	while(tst--)
	{
		scanf("%d%d%d",&n,&m,&p);
		for(int i=2;i<=n;i++)
		{
			scanf("%d",d+i);
			d[i]+=d[i-1];
		}
		ll ans=0;
		for(int i=1;i<=m;i++)
			scanf("%d%d",h+i,t+i),t[i]-=d[h[i]],ans-=t[i];
		// printf("ans:%d\n",ans);
		sort(t+1,t+m+1);
		// for(int i=1;i<=m;i++)
		// 	printf("i:%d t:%d\n",i,t[i]);
		memset(f,0x3F,sizeof(f));
		for(int k=1;k<=p;k++)
		{
			f[k-1][0]=0;
			int tp=0,lp=1;
			st[++tp]=pt(0,0);
			for(int i=1;i<=m;i++)
			{
				while(lp<tp&&st[lp+1].y-st[lp+1].x*t[i]<=st[lp].y-st[lp].x*t[i])
					lp++;
				f[k][i]=st[lp].y-st[lp].x*t[i]+(ll)i*t[i];
				// printf("k:%d i:%d x:%d y:%d f:%d\n",k,i,st[lp].x,st[lp].y,f[k][i]);
				pt np(i,f[k-1][i]);
				while(tp>1&&cross(st[tp-1],st[tp],np)<=0)
					tp--;
				st[++tp]=np;
				lp=min(lp,tp);
			}
		}
		printf("%lld\n",f[p][m]+ans);
	}
	return 0;
}