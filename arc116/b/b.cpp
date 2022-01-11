#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n;
int s[200009],mul[200009];
int main()
{
	scanf("%d",&n);
	mul[0]=1;
	for(int i=1;i<=n;i++)
		mul[i]=mul[i-1]*2%mod;
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	sort(s+1,s+n+1);
	s[n+1]=-1;
	int ans=0,lp=0,psm=0;
	for(int i=1;i<=n;i++)
		if(s[i]!=s[i+1])
		{
			int rp=mul[i-lp]-1;
			int tmp=(ll)rp*s[i]%mod*psm%mod;
			tmp=(tmp+(ll)rp*s[i]%mod*s[i])%mod;
			(ans+=tmp)%=mod;
			psm=((ll)psm*mul[i-lp]+(ll)rp*s[i])%mod;
			lp=i;
		}
	printf("%d",ans);
	return 0;
}