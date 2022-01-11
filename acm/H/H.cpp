#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n,m;
int mul[1000009],inv[1000009];
int smi[1000009];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
void init()
{
	int k=1000000;
	mul[0]=1;
	for(int i=1;i<=k;i++)
		mul[i]=(ll)mul[i-1]*i%mod;
	inv[k]=qpow(mul[k],mod-2);
	for(int i=k;i>=1;i--)
		inv[i-1]=(ll)inv[i]*i%mod;
	for(int i=1;i<=k;i++)
		smi[i]=(smi[i-1]+inv[i])%mod;
}
int main()
{
	init();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int ans=(ll)mul[m]*mul[n-m+1]%mod;
		ans=(ans+(ll)mul[m]*mul[n-m]%mod*(m-1))%mod;
		ans=(ans-(ll)mul[m]*mul[n-m]%mod*smi[m-1]%mod*inv[n-m]%mod+mod)%mod;
		printf("%d\n",ans);
	}
	return 0;
}