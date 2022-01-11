#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n,m,x[2],y[2];
int inv[1000009];
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
	inv[1]=1;
	for(int i=2;i<=1000000;i++)
		inv[i]=(ll)inv[mod%i]*(mod-mod/i)%mod;
	// for(int i=1;i<=10;i++)
	// 	printf("i:%d inv:%d\n",i,inv[i]);
}
int main()
{
	scanf("%d%d",&n,&m);
	init();
	scanf("%d%d%d%d",x,y,x+1,y+1);
	sort(x,x+2);
	sort(y,y+2);
	int s[4];
	s[0]=x[0]-1,s[1]=n-x[1],s[2]=y[0]-1,s[3]=m-y[1];
	int sm=x[1]-x[0]+y[1]-y[0];
	int ans=1;
	for(int i=0;i<4;i++)
	{
		// printf("i:%d s:%d sm:%d\n",i,s[i],sm);
		for(int j=1;j<=s[i];j++)
			(ans+=(ll)inv[j+sm])%=mod;
	}
	printf("%d",ans);
	return 0;
}