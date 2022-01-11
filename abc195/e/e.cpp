#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
char s[100009],t[100009];
int rm[100009];
int f[100009][7];//1:Takahashi 0:Aoki
int main()
{
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	rm[n]=1;
	for(int i=n-1;i>=1;i--)
		rm[i]=rm[i+1]*3%7;
	f[n+1][0]=1;
	for(int i=n;i>=1;i--)
	{
		s[i]=(s[i]-'0')%7;
		for(int j=0;j<=6;j++)
		{
			if(t[i]=='T')
			{
				if(f[i+1][j]||f[i+1][(j+s[i]*rm[i])%7])
					f[i][j]=1;
				else
					f[i][j]=0;
			}
			else//Aoki
			{
				if(f[i+1][j]==0||f[i+1][(j+s[i]*rm[i])%7]==0)
					f[i][j]=0;
				else
					f[i][j]=1;
			}
		}
	}
	printf("%s",f[1][0]?"Takahashi":"Aoki");
	return 0;
}