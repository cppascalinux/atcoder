#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define mod 998244353
using namespace std;
int n,m;
int s[3009];
int f[3009][3009];
int mul[3009],inv[3009];
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
	mul[0]=1;
	for(int i=1;i<=n;i++)
		mul[i]=(ll)mul[i-1]*i%mod;
	inv[n]=qpow(mul[n],mod-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=(ll)inv[i]*i%mod;
}
int cb(int a,int b)
{
	return b<0||b>a?0:(ll)mul[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	f[0][0]=1;
	for(int i=1;i<=m;i++)
		for(int j=0;j<=min(i,n);j++)
		{
			f[i][j]=(ll)f[i-1][j]*2*j%mod;
			(f[i][j]+=j>=1?f[i-1][j-1]:0)%=mod;
		}
	int ans=0;
	for(int i=0;i<=n;i++)
		for(int j=i+1;j<=n+1;j++)
		{
			if(j>i+2&&s[j-1]<s[j-2])
				break;
			int tf=(ll)f[m][i+(n-j+1)]*cb(i+(n-j+1),i)%mod;
			(ans+=tf)%=mod;
		}
	printf("%d",ans);
	return 0;
}