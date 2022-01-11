#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
char s[1009];
int mat[1009][1009];
int f[1000009];
int br[1000009],bc[1000009];
int vr[1009],vc[1009];
vector<int> sr[1009],sc[1009],sf[1000009];
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			mat[i][j]=s[j]=='.'?0:1;
	}
	mat[1][1]=mat[1][m]=mat[n][1]=mat[n][m]=1;
	// for(int i=1;i<=n;i++)
	// 	for(int j=1;j<=m;j++)
	// 		printf("%d%c",mat[i][j],j==m?'\n':' ');
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int num=(i-1)*m+j;
			br[num]=i;
			bc[num]=j;
			if(mat[i][j])
			{
				sr[i].push_back(num);
				sc[j].push_back(num);
			}
		}
	for(int i=1;i<=n*m;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
	{
		int lst=0;
		for(int u:sr[i])
		{
			// printf("i:%d u:%d\n",i,u);
			if(lst)
				f[fnd(u)]=fnd(lst);
			else
				lst=u;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int lst=0;
		for(int u:sc[i])
			if(lst)
				f[fnd(u)]=fnd(lst);
			else
				lst=u;
	}
	// for(int i=1;i<=n*m;i++)
	// 	printf("i:%d fnd:%d\n",i,fnd(i));
	for(int i=1;i<=n*m;i++)
		sf[fnd(i)].push_back(i);
	int ansr=-1,ansc=-1;
	for(int i=1;i<=n*m;i++)
	{
		if(sf[i].size()>1)
		{
			int tr=0,tc=0;
			for(int u:sf[i])
			{
				// printf("i:%d u:%d\n",i,u);
				if(!vr[br[u]])
					vr[br[u]]=1,tr++;
				if(!vc[bc[u]])
					vc[bc[u]]=1,tc++;
			}
			ansr++,ansc++;
		}
	}
	for(int i=1;i<=n;i++)
		if(!vr[i])
			ansr++;
	for(int i=1;i<=m;i++)
		if(!vc[i])
			ansc++;
	printf("%d",min(ansr,ansc));
	return 0;
}