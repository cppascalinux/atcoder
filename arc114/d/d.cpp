#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define inf 0x7F7F7F7F7F7F7F7FLL
using namespace std;
int n,k,m;
int sa[5009],st[5009];
int qb[5009];
ll f[5009][5009];//first i a, j is used for matching b
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",sa+i);
	sort(sa+1,sa+n+1);
	for(int i=1;i<=k;i++)
		scanf("%d",st+i);
	map<int,int> sb;
	for(int i=1;i<=n;i++)
		sb[sa[i]]^=1;
	for(int i=1;i<=k;i++)
		sb[st[i]]^=1;
	for(pii t:sb)
		if(t.se)
			qb[++m]=t.fi;
	if(m>n)
		return printf("-1"),0;
	memset(f,0x7F,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=min(i,m);j++)
			if(f[i][j]<inf)
			{
				if(j+1<=m)
					f[i+1][j+1]=min(f[i+1][j+1],f[i][j]+abs(sa[i+1]-qb[j+1])+((i-j)&1)*(sa[i+1]-sa[i]));
				f[i+1][j]=min(f[i+1][j],f[i][j]+((i-j)&1)*(sa[i+1]-sa[i]));
			}
	}
	printf("%lld",f[n][m]);
	return 0;
}