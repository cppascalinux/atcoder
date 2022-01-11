#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n;
int s[200009],f[200009];
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		scanf("%d",s+i),f[fnd(s[i])]=fnd(i);
	int ans=1;
	for(int i=1;i<=n;i++)
		if(fnd(i)==i)
			ans=ans*2%mod;
	printf("%d",(ans+mod-1)%mod);
	return 0;
}