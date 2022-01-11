#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7F7F7F7F7F7F7F7FLL
#define ll long long
using namespace std;
ll x,y,p,q;
ll m1,m2,g;
ll gcd(ll a,ll b)
{
	return !a||!b?a+b:gcd(b,a%b);
}
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
ll cal(int a,int b)
{
	ll r1=x+a,r2=p+b;
	ll t=r2-r1;
	if(t%g!=0)
		return inf;
	ll x,y;
	exgcd(m1,m2,x,y);
	x*=t/g,y*=t/g;
	ll ad1=m2/g,ad2=m1/g;
	ll nx=(x%ad1+ad1)%ad1;
	ll rp=(nx-x)/ad1;
	ll ny=y-ad2*rp;
	if(ny>0)
	{
		ll my=(ny%ad2-ad2)%ad2;
		ll tp=(my-ny)/ad2;
		nx-=ad1*tp;
	}
	return nx*m1+r1;
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&x,&y,&p,&q);
		m1=2*x+2*y,m2=p+q;
		g=gcd(m1,m2);
		ll ans=inf;
		for(int i=0;i<=y-1;i++)
			for(int j=0;j<=q-1;j++)
				ans=min(ans,cal(i,j));
		if(ans==inf)
			printf("infinity\n");
		else
			printf("%lld\n",ans);
	}
	return 0;
}