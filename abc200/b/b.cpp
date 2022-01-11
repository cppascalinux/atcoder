#include<bits/stdc++.h>
#define ll long long
using namespace std;
void out(__int128 x)
{
	if(!x)
		return;
	out(x/10);
	printf("%d",(int)(x%10));
}
int main()
{
	ll n,k;
	scanf("%lld%lld",&n,&k);
	__int128 p=n;
	for(int i=1;i<=k;i++)
	{
		if(p%200==0)
			p/=200;
		else
			p=p*1000+200;
	}
	out(p);
	return 0;
}