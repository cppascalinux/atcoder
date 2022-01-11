#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,c0;
int vl[100009];
ll f[1000009],sm[1000009];
int bn[40009];
int mp[40009];
ll g1[40009],g2[40009];
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		// scanf("%d%d",&n,&c0);
		memset(f,0,sizeof(f));
		memset(sm,0,sizeof(sm));
		memset(bn,0,sizeof(bn));
		memset(g1,0,sizeof(g1));
		memset(g2,0,sizeof(g2));
		c0=100000000;
		int sqrtk=min(c0,33000);
		int k13=min(c0,1000);
		int k23=min(c0,1000000);
		vector<int> vs;
		// for(int i=1;i<=n;i++)
		// {
		// 	scanf("%d",vl+i);
		// 	if(vl[i]<=k13)
		// 		bn[vl[i]]=1;
		// 	else
		// 		vs.push_back(vl[i]);
		// }
		for(int i=1;i<=9998;i++)
			bn[i]=1;
		sort(vs.begin(),vs.end());
		f[1]=1;
		for(int i=1;i<=k13;i++)
			if(!bn[i])
			{
				int rk=k23/i;
				for(int j=rk;j>=1;j--)
					f[j*i]+=f[j];
			}
		for(int i=1;i<=k23;i++)
		{
			sm[i]=sm[i-1]+f[i];
			// printf("i:%d f:%lld sm:%lld\n",i,f[i],sm[i]);
		}
		ll ans=0;
		if(k13<c0)
		{
			for(int l=k13+1,r;l<=c0;l=r+1)
			{
				r=c0/(c0/l);
				if(l==10001)
					printf("l:%d r:%d sm:%lld\n",l,r,sm[c0/l]);
				auto rb=upper_bound(vs.begin(),vs.end(),r);
				auto lb=lower_bound(vs.begin(),vs.end(),l);
				// printf("l:%d r:%d lt:%d\n",l,r,rb-lb);
				ans+=((r-l+1)-(rb-lb))*sm[c0/l];
			}
			printf("ans:%lld\n",ans),fflush(stdout);
		}
		for(int i=1;i<=sqrtk;i++)
		{
			mp[i]=c0/i;
			if(mp[i]<=sqrtk)
				mp[i]=0;
			// printf("i:%d c/i:%d mp:%d\n",i,c0/i,mp[i]);
		}
		if(mp[1])
			g2[1]=1;
		else
			g1[c0]=1;
		for(int i=1;i<=k13;i++)
			if(!bn[i])
			{
				for(int j=i;j<=sqrtk;j++)
					g1[j/i]+=g1[j];
				for(int j=sqrtk;j>=1;j--)
					if(mp[j])
					{
						int v=mp[j];
						int nv=v/i;
						if(nv<=sqrtk)
							g1[nv]+=g2[j];
						else
							g2[c0/nv]+=g2[j];
					}
			}
		for(int i=1;i<=sqrtk;i++)
		{
			// printf("i:%d g1:%lld g2:%lld\n",i,g1[i],g2[i]);
			ans+=g1[i];
			if(mp[i])
				ans+=g2[i];
		}
		printf("%lld\n",ans-1);
	}
	return 0;
}