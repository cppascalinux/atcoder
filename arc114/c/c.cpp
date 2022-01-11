 #include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n,m;
int mul[5009][5009];
int sm[5009][5009];
void init()
{
	for(int i=0;i<=m;i++)
	{
		mul[i][0]=1;
		for(int j=1;j<=n;j++)
		{
			mul[i][j]=(ll)mul[i][j-1]*i%mod;
			// printf("i:%d j:%d mul:%d\n",i,j,mul[i][j]);
		}
	}
	memcpy(sm,mul,sizeof(sm));
	for(int j=0;j<=n;j++)
		for(int i=1;i<=m;i++)
		{
			(sm[i][j]+=sm[i-1][j])%=mod;
			// printf("i:%d j:%d sm:%d\n",i,j,sm[i][j]);
		}
}
void solve()
{
	int ans=(ll)mul[m][n]*n%mod;
	int rv=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i-1;j++)
		{
			// int tm=(ll)sm[m-1][i-j-1]*mul[m][j-1]%mod;
			// printf("i:%d j:%d tm:%d\n",i,j,tm);
			rv=(rv+(ll)sm[m-1][i-j-1]*mul[m][j-1]%mod*mul[m][n-i])%mod;
		}
	}
	ans=(ans-rv+mod)%mod;
	printf("%d",ans);
}
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
	init();
	solve();
	return 0;
}