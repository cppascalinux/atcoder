#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll k;
ll cb3(int x)
{
	ll ans=(ll)(x-1)*(x-2)/2;
	if(x>=n+3)
		ans-=3LL*(x-n-1)*(x-n-2)/2;
	if(x>=2*n+3)
		ans+=3LL*(x-2*n-1)*(x-2*n-2)/2;
	return ans;
}
ll cb2(int x)
{
	ll ans=x-1;
	if(x>=n+2)
		ans-=2*(x-n-1);
	if(x>=2*n+2)
		ans+=x-2*n-1;
	return ans;
}
ll cb1(int x)
{
	return x>=1&&x<=n?1:0;
}
int main()
{
	scanf("%d%lld",&n,&k);
	int sm=0;
	for(int i=3;i<=3*n;i++)
	{
		if(k>cb3(i))
			k-=cb3(i);
		else
		{
			sm=i;
			break;
		}
	}
	// printf("k:%d sm:%d\n",k,sm);
	int p=0;
	for(int i=1;i<=sm-2;i++)
	{
		if(k>cb2(sm-i))
			k-=cb2(sm-i);
		else
		{
			p=i;
			break;
		}
	}
	int q=0;
	for(int i=1;i<=sm-p-1;i++)
	{
		if(k>cb1(sm-p-i))
			k-=cb1(sm-p-i);
		else
		{
			q=i;
			break;
		}
	}
	printf("%d %d %d",p,q,sm-p-q);
	return 0;
}