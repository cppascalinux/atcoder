#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
int k,n,emp=1,ans,inv2;
char bk[100009],s[100009];
int qpow(int a,ll b)
{
	// assert(b>=0);
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
int cal(ll len)
{
	return (len+1)%mod*qpow(2,len-1)%mod;
}
int getn(ll len,ll fre)
{
	assert(len>0);
	return (ll)cal(len)*qpow(2,fre-len)%mod;
}
void solve(int bg,int ed)
{
	if(s[1]!=-1&&s[1]!=bg)
		return;
	if(s[n]!=-1&&s[n]!=ed)
		return;
	if(n==1&&k==1&&bg!=ed)
		return;
	ll fre=0;
	int num=0,org=0;
	for(int i=1;i<=n;i++)
		fre+=(s[i]==-1);
	fre*=k;
	fre-=(s[1]==-1);
	fre-=(s[n]==-1);
	num=qpow(2,fre);
	int sm=bg==ed?0:num;
	if(emp)
	{
		if(fre)
			(sm+=cal(fre))%=mod;
		else
			(sm+=bg!=ed)%=mod;
		ans=(ans+(ll)sm*inv2)%mod;
		// printf("bg:%d ed:%d ans:%d num:%d\n",bg,ed,ans,num);
		return;
	}
	for(int i=1;i<=n-1;i++)
		if(s[i]!=-1&&s[i+1]!=-1&&s[i]!=s[i+1])
			(org+=k)%=mod;
	if(s[1]!=-1&&s[n]!=-1&&s[1]!=s[n])
		(org+=k-1)%=mod;
	if(s[1]==-1&&s[2]!=-1&&bg!=s[2])
		(++org)%=mod;
	if(s[n]==-1&&s[n-1]!=-1&&ed!=s[n-1])
		(++org)%=mod;
	sm=(sm+(ll)org*num)%mod;
	int lp=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==-1)
			lp=i;
		else
			break;
	}
	int rp=n+1;
	for(int i=n;i>=1;i--)
	{
		if(s[i]==-1)
			rp=i;
		else
			break;
	}
	// printf("lp:%d rp:%d\n",lp,rp);
	if(lp>1)
		(sm+=getn(lp-1,fre))%=mod;
	if(rp<n)
		(sm+=getn(n-rp,fre))%=mod;
	if(lp+n+1-rp>0&&k>1)
		sm=(sm+(ll)getn(lp+(n+1-rp),fre)*(k-1))%mod;
	lp++,rp--;
	int lst=lp;
	for(int i=lp;i<=rp;i++)
	{
		// printf("i:%d\n",i);
		if(s[i]!=-1)
		{
			if(i>lst+1)
				sm=(sm+(ll)getn(i-lst-1,fre)*k)%mod;
			lst=i;
		}
	}
	ans=(ans+(ll)sm*inv2)%mod;
}
int main()
{
	inv2=qpow(2,mod-2);
	scanf("%s%d",s+1,&k);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i]=='?'?-1:s[i]-'0';
		if(s[i]!=-1)
			emp=0;
	}
	if((ll)n*k==1)
		return printf("0"),0;
	for(int i:{0,1})
		for(int j:{0,1})
			solve(i,j);
	printf("%d",ans);
	return 0;
}