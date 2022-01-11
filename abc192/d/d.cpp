#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define i128 __int128
using namespace std;
int d;
char s[109];
ll m;
vector<int> v;
int judge(ll t)
{
	i128 ans=0;
	for(int s:v)
	{
		ans=ans*(i128)t+(i128)s;
		if(ans>m)
			return 0;
	}
	return 1;
}
int main()
{
	scanf("%s",s+1);
	scanf("%lld",&m);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
		d=max(d,s[i]-'0'),v.push_back(s[i]-'0');
	if(v.size()<=1)
		return printf("%d",v[0]<=m?1:0),0;
	// reverse(v.begin(),v.end());
	// for(int t:v)
	// 	printf("%d ",t);
	ll l=d,r=m+10;
	while(l<r)
	{
		ll md=(l+r+1)/2;
		// printf("md:%lld jd:%d\n",md,judge(md));
		if(judge(md))
			l=md;
		else
			r=md-1;
	}
	printf("%lld",l-d);
	return 0;
}