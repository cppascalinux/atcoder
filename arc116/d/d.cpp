#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n,m;
int cb[5009][5009];
int f[20][5009];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
		cb[i][i]=cb[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			cb[i][j]=(cb[i-1][j]+cb[i-1][j-1])%mod;
	f[0][0]=1;
	for(int i=1;i<=13;i++)//bits
	{
		for(int j=m;j>=0;j--)//already used
		{
			for(int k=0;k*(1<<(i-1))<=j;k+=2)
			{
				f[i][j]=(f[i][j]+(ll)f[i-1][j-k*(1<<(i-1))]*cb[n][k])%mod;
			}
		}
	}
	printf("%d",f[13][m]);
	return 0;
}