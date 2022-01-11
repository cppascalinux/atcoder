#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int n;
char s[200009];
vector<int> p[30];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		s[i]-='a'-1;
		p[s[i]].push_back(i);
	}
	int lp=n+1,ls=0;
	ll ans=0;
	for(int i=n;i>=2;i--)
	{
		if(s[i]==s[i-1])
		{
			if(i>=lp)
				continue;
			int sm=s[i]==ls?max(lp-i-1,0):n-i;
			int rp=lower_bound(p[s[i]].begin(),p[s[i]].end(),lp)-lower_bound(p[s[i]].begin(),p[s[i]].end(),i+1);
			// printf("i:%d lp:%d ls:%d sm:%d rp:%d\n",i,lp,ls,sm,rp);
			ans+=sm-rp;
			ls=s[i];
			lp=i-1;
		}
	}
	printf("%lld",ans);
	return 0;
}