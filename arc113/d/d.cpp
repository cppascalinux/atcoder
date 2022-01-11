#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define mod 998244353
using namespace std;
int n,m,k;
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
	scanf("%d%d%d",&n,&m,&k);
	if(n==1||m==1)
	{
		int ans=qpow(k,n*m);
		printf("%d",ans);
		return 0;
	}
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		int sm1=(qpow(i,n)-qpow(i-1,n)+mod)%mod;
		int sm2=qpow(k-i+1,m)%mod;
		ans=(ans+(ll)sm1*sm2)%mod;
	}
	printf("%d",ans);
	return 0;
}