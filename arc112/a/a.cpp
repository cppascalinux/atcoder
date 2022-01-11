#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		ll ans=0;
		int t=(r-2*l+1);
		if(t>0)
			ans=(ll)t*(t+1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}