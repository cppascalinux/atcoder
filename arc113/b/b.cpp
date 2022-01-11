#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int qpow(int a,int b,int mod)
{
	a%=mod;
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int r2=0,r5=0;
	r2=a%2;
	int sb=qpow(b,c,4);
	r5=a%5==0?0:qpow(a,sb,5);
	int ans=(r5%2==r2?r5:r5+5);
	printf("%d",ans);
	return 0;
}