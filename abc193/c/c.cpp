#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define ll long long
using namespace std;
ll n;
ll chk(int a,int b)
{
	ll ans=1;
	for(int i=1;i<=b;i++)
	{
		ans*=(ll)a;
		if(ans>n)
			return 0;
	}
	return ans;
}
int main()
{
	scanf("%lld",&n);
	set<ll> s;
	for(int i=2;i<=40;i++)
		for(int j=2;(ll)j*j<=n;j++)
		{
			ll t=chk(j,i);
			if(t)
				s.insert(t);
			else
				break;
		}
	printf("%lld",n-s.size());
	return 0;
}