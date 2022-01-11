#include<bits/stdc++.h>
#define db double
#define eps 1e-8
using namespace std;
int n;
int sgn(db v)
{
	return v>eps?1:v<-eps?-1:0;
}
struct pt
{
	db x,y;
	pt():x(0),y(0){}
	pt(db a,db b):x(a),y(b){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator/(db v){return pt(x/v,y/v);}
	db operator*(pt p){return x*p.x+y*p.y;}
	db operator^(pt p){return x*p.y-y*p.x;}
	db getl(){return sqrt(x*x+y*y);}
	db getl2(){return x*x+y*y;}
	db geta(){if(sgn(getl())==0) return -100;return atan2(y,x);}
	bool operator<(const pt &p)const{return x<p.x||(x==p.x&&y<p.y);}
};
pt s[109],w[109];
pt t[109];
int vis[109];
bool cmp(pt &a,pt &b)
{
	return a<b;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&s[i].x,&s[i].y);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&w[i].x,&w[i].y);
	pt qs,qw;
	for(int i=1;i<=n;i++)
		qs=qs+s[i],qw=qw+w[i];
	qs=qs/n,qw=qw/n;
	for(int i=1;i<=n;i++)
		s[i]=s[i]-qs,w[i]=w[i]-qw;
	sort(s+1,s+n+1,cmp);
	sort(w+1,w+n+1,cmp);
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d x:%lf y:%lf\n",i,s[i].x,s[i].y);
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d x:%lf y:%lf\n",i,w[i].x,w[i].y);
	int ps=0,ans=0;
	for(int i=1;i<=n;i++)
		if(sgn(s[i].getl())!=0)
		{
			ps=i;
			break;
		}
	if(!ps)
		return printf("Yes\n"),0;
	for(int i=1;i<=n;i++)
		if(sgn(s[ps].getl2()-w[i].getl2())==0)
		{
			// printf("ps:%d i:%d\n",ps,i);
			db rl=s[ps]*w[i]/w[i].getl2();
			db im=(w[i]^s[ps])/w[i].getl2();
			int sft=(i-ps+n)%n,fg=1;
			memset(vis,0,sizeof(vis));
			for(int j=1;j<=n;j++)
			{
				pt np=w[j];
				db nx=np.x*rl-np.y*im;
				db ny=np.x*im+np.y*rl;
				// printf("st:%lf %lf p:%lf %lf np:%lf %lf\n",st.x,st.y,np.x,np.y,nx,ny);
				t[j]=pt(nx,ny);
				int tl=0;
				for(int k=1;k<=n;k++)
					if(!vis[k]&&sgn((s[k]-t[j]).getl2())==0)
						vis[k]=tl=1;
				if(!tl)
					fg=0;
			}
			// sort(t+1,t+n+1,cmp);
			// for(int j=1;j<=n;j++)
			// 	if(sgn((s[j]-t[j]).getl2()))
			// 		fg=0;
			if(fg)
			{
				ans=1;
				break;
			}
		}
	printf("%s\n",ans?"Yes":"No");
	return 0;
}