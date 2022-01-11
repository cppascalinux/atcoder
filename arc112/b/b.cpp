#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	ll x,c;
	scanf("%lld%lld",&x,&c);
	ll ans=0;
	if(c==1)
	{
		ans=x==0?1:2;
	}
	else if(x==0)
	{
		ans+=c/2+1;
		ans+=(c-1)/2;
	}
	else if(x<0)
	{
		ans+=c/2+1;
		ans+=(c-1)/2+1;
		ll mn=-x-(c-1)/2;
		ll mx=x+(c-2)/2;
		if(mx>=mn)
			ans+=-x-1-x;
		else
			ans+=(mx-x)+(-x-mn);
	}
	else 
	{
		ans+=(c-1)/2+1;
		ans+=(c-2)/2+1;
		ll mn=x-c/2;
		ll mx=-x+(c-1)/2;
		if(mx>=mn)
			ans+=x-1-(-x);
		else
			ans+=(x-mn)+(mx-(-x));
	}
	printf("%lld",ans);
	return 0;
}