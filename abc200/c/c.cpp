#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int s[200009];
int sm[209];
int main()
{
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",s+i);
		ans+=sm[s[i]%200];
		sm[s[i]%200]++;
	}
	printf("%lld",ans);
	return 0;
}