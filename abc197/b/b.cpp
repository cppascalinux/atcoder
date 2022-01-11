#include<bits/stdc++.h>
using namespace std;
int h,w,x,y;
int mat[109][109];
int main()
{
	scanf("%d%d%d%d",&h,&w,&x,&y);
	char s[109];
	for(int i=1;i<=h;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=w;j++)
			if(s[j]=='#')
				mat[i][j]=1;
	}
	int ans=1;
	for(int i=x-1;i>=1&&!mat[i][y];i--)
		ans++;
	for(int i=x+1;i<=h&&!mat[i][y];i++)
		ans++;
	for(int j=y-1;j>=1&&!mat[x][j];j--)
		ans++;
	for(int j=y+1;j<=w&&!mat[x][j];j++)
		ans++;
	printf("%d",ans);
	return 0;
}