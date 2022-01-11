#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n,m;
int mul[200009],inv[200009];
int f[200009][19];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	mul[0]=1;
	for(int i=1;i<=n;i++)
		mul[i]=(ll)mul[i-1]*i%mod;
	inv[n]=qpow(mul[n],mod-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=(ll)inv[i]*i%mod;
	// for(int i=0;i<=n;i++)
	// 	printf("mul:%d inv:%d\n",mul[i],inv[i]);
	f[1][0]=1;
	for(int i=2;i<=m;i++)//the number chosen
	{
		for(int k=m/i;k>=1;k--)//start position
		{
			ll v=i;
			for(int j=1;v*k<=m;j++,v*=i)//repetition times
			{
				for(int l=0;l+j<=18&&l+j<=n;l++)//initial repetition
				{
					// printf("i:%d j:%d k:%d l:%d kv:%d f:%d\n",i,j,k,l,k*v,f[k][l]);
					f[k*v][l+j]=(f[k*v][l+j]+(ll)f[k][l]*inv[j])%mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<=18&&j<=n;j++)
			ans=(ans+(ll)f[i][j]*inv[n-j])%mod;
	ans=(ll)ans*mul[n]%mod;
	printf("%d",ans);
	return 0;
}