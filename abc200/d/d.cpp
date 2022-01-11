#include<bits/stdc++.h>
using namespace std;
int n;
int ansv=-1,ansx=0,ansy=0;
int s[209];
int f[2][209][209];
void solve()
{
	for(int v=0;v<200;v++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(f[1][i][v]&&f[1][j][v])
				{
					ansv=v,ansx=i,ansy=j;
					return;
				}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i),s[i]%=200;
	f[0][0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<200;j++)
		{
			f[0][i][j]|=f[0][i-1][j]|f[1][i-1][j];
			f[1][i][(j+s[i])%200]|=f[0][i-1][j]|f[1][i-1][j];
		}
	solve();
	if(ansv>=0)
	{
		vector<int> sx,sy;
		for(int i=ansx,v=ansv,p=1;i;i--)
		{
			if(p)
				sx.push_back(i);
			if(p)
				v=(v+200-s[i])%200;
			if(f[1][i-1][v])
				p=1;
			else
				p=0;
		}
		for(int i=ansy,v=ansv,p=1;i;i--)
		{
			if(p)
				sy.push_back(i);
			if(p)
				v=(v+200-s[i])%200;
			if(f[1][i-1][v])
				p=1;
			else
				p=0;
		}
		printf("yes\n");
		sort(sx.begin(),sx.end());
		printf("%d ",(int)sx.size());
		for(int v:sx)
			printf("%d ",v);
		printf("\n");
		sort(sy.begin(),sy.end());
		printf("%d ",(int)sy.size());
		for(int v:sy)
			printf("%d ",v);
		return 0;
	}
	for(int i=1;i<n;i++)
		if(f[1][i][0])
		{
			vector<int> sx,sy;
			sx.push_back(i+1),sy.push_back(i+1);
			for(int j=i,v=0,p=1;j;j--)
			{
				if(p)
					sx.push_back(j);
				if(p)
					v=(v+200-s[j])%200;
				if(f[1][j-1][v])
					p=1;
				else
					p=0;
			}
			printf("yes\n");
			sort(sx.begin(),sx.end());
			printf("%d ",(int)sx.size());
			for(int v:sx)
				printf("%d ",v);
			printf("\n");
			sort(sy.begin(),sy.end());
			printf("%d ",(int)sy.size());
			for(int v:sy)
				printf("%d ",v);
			return 0;
		}
	printf("no");
	return 0;
}