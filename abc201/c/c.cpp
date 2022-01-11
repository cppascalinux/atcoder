#include<bits/stdc++.h>
using namespace std;
char s[20];
int main()
{
	scanf("%s",s);
	int ans=0;
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
				for(int l=0;l<=9;l++)
				{
					int fg=1;
					for(int d=0;d<=9;d++)
					{
						if(s[d]=='o')
						{
							if(i!=d&&j!=d&&k!=d&&l!=d)
								fg=0;
						}
						else if(s[d]=='x')
						{
							if(!(i!=d&&j!=d&&k!=d&&l!=d))
								fg=0;
						}
					}
					ans+=fg;
				}
	printf("%d",ans);
	return 0;
}