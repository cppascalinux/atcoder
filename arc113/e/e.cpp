#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char s[200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		if(n<=2)
		{
			printf("%s\n",s+1);
			continue;
		}
		int sm[2]={0,0};
		for(int i=1;i<=n;i++)
			s[i]-='a',sm[s[i]]++;
		int ls=0,ptt=0;
		for(int i=1;i<=n-1;i++)
		{
			if(s[i]!=s[i+1])
			{
				int len=i-ls;
				ls=i;
				if(s[i]==0)
					ptt+=len>=2?2:1;
			}
		}
		if(s[n]==0)
		{
			for(int i=1;i<=sm[1];i++)
				printf("b");
			for(int i=1;i<=sm[0]-(ptt+1)/2*2;i++)
				printf("a");
			printf("\n");
			continue;
		}
		if(sm[0]%2==0)
		{
			for(int i=1;i<=sm[1];i++)
				printf("b");
			printf("\n");
			continue;
		}
		if(s[n-1]==0)
		{
			for(int i=1;i<=sm[1]-1;i++)
				printf("b");
			printf("ab\n");
			continue;
		}
		if(s[n-2]==0)
		{
			for(int i=1;i<=sm[1]-2;i++)
				printf("b");
			printf("abb\n");
			continue;
		}
		if((ptt==1&&s[1]==0)||(ptt==2&&s[1]==0&&s[2]==0))
		{
			printf("a");
			for(int i=1;i<=sm[1];i++)
				printf("b");
			printf("\n");
			continue;
		}
		int fg=0;
		for(int i=1;i<=n-2;i++)
			if(s[i]==1&&s[i+1]==0&&s[i+2]==0)
				fg=1;
		if(fg)
		{
			for(int i=1;i<=sm[1]-2;i++)
				printf("b");
			for(int i=1;i<=sm[0]-(ptt-1)/2*2;i++)
				printf("a");
			printf("\n");
			continue;
		}
		for(int i=1;i<=sm[1]-2;i++)
			printf("b");
		for(int i=1;i<=sm[0]-ptt/2*2;i++)
			printf("a");
		printf("\n");
	}
	return 0;
}