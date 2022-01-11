#include<bits/stdc++.h>
#define ll long long
using namespace std;
int rp[20];
ll n;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=16;i++)
		rp[i]=(i-1)/3;
	ll ans=0;
	for(int i=1;i<=16;i++)
	{
		ll rt=1;
		for(int j=1;j<=i-1;j++)
			rt*=10;
		if(n<rt)
			break;
		ans+=(min(rt*10-1,n)-rt+1)*rp[i];
	}
	printf("%lld",ans);
	return 0;
}