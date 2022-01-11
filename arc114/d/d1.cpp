#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	int v,cl;
	bool operator<(const node &p)const{return v<p.v;}
};
int n,k;
int s[5009],t[5009];
node q[10009];
ll f[10009][2];
int g[10009][2];
int main()
{
	scanf("%d%d",&n,&k);
	map<int,int> mp;
	for(int i=1;i<=n;i++)
		scanf("%d",s+i),mp[s[i]]^=1;
	for(int i=1;i<=k;i++)
		scanf("%d",t+i),mp[t[i]]^=1;
	int tp=0;
	for(auto t:mp)
		if(t.second)
			q[++tp]=node{t.first,1};
	if(tp>k)
		return printf("-1"),0;
	for(int i=1;i<=n;i++)
		q[++tp]=node{s[i],0};
	sort(q+1,q+tp+1);
	memset(f,0x1F,sizeof(f));
	int sm[2]={0};
	f[0][0]=f[0][1]=0;
	g[0][0]=g[0][1]=0;
	q[0]=q[1];
	for(int i=1;i<=tp;i++)
	{
		sm[q[i].cl]++;
		int l=q[i].v-q[i-1].v;
		if(sm[1]==sm[0])
		{
			if(q[i].cl==0)
				f[i][0]=f[i][1]=min(f[i][1],f[i-1][1]+(ll)g[i-1][1]*l);
			else
				f[i][0]=f[i][1]=min(f[i][1],f[i-1][0]+(ll)g[i-1][0]*l);
			g[i][0]=g[i][1]=0;
		}
		else if(sm[1]>sm[0])
		{
			f[i][1]=min(f[i][1],f[i-1][1]+(ll)g[i-1][1]*l);
			g[i][1]=sm[1]-sm[0];
		}
		else
		{
			if((sm[0]-sm[1])&1)
			{
				f[i][0]=min(f[i][0],f[i-1][0]);
				g[i][0]=1;
			}
			else
			{
				f[i][0]=min(f[i][0],f[i-1][0]+l);
				g[i][0]=0;
			}
		}
	}
	ll ans=min(f[tp][0],f[tp][1]);
	printf("%lld",ans);
	return 0;
}