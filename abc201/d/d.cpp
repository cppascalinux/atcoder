#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[2009];
int mat[2009][2009];
int f[2009][2009];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			mat[i][j]=s[j]=='+'?1:-1;
	}
	memset(f,0x80,sizeof(f));
	f[n][m]=0;
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--)
		{
			if(i+1<=n)
				f[i][j]=max(f[i][j],-f[i+1][j]+mat[i+1][j]);
			if(j+1<=m)
				f[i][j]=max(f[i][j],-f[i][j+1]+mat[i][j+1]);
		}
	if(f[1][1]>0)
		puts("Takahashi");
	else if(f[1][1]==0)
		puts("Draw");
	else
		puts("Aoki");
	return 0;
}