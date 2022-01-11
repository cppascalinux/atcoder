#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define db double
#define ll long long
using namespace std;
int k;
int sm[11],buc[11];
char s[10],t[10];
ll cal(char *s)
{
	for(int i=1;i<=9;i++)
		buc[i]=0;
	for(int i=1;i<=5;i++)
		buc[s[i]]++;
	ll ans=0;
	for(int i=1;i<=9;i++)
	{
		int rp=1;
		for(int j=1;j<=buc[i];j++)
			rp*=10;
		ans+=(ll)i*rp;
	}
	return ans;
}
int main()
{
	scanf("%d%s%s",&k,s+1,t+1);
	for(int i=1;i<=4;i++)
		s[i]-='0',t[i]-='0';
	for(int i=1;i<=9;i++)
		sm[i]=k;
	for(int i=1;i<=4;i++)
		sm[s[i]]--,sm[t[i]]--;
	int tot=0;
	for(int i=1;i<=9;i++)
		tot+=sm[i];
	db ans=0;
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
		{
			s[5]=i,t[5]=j;
			if(cal(s)>cal(t))
			{
				db p1=(db)sm[i]/tot;
				sm[i]--;
				db p2=(db)sm[j]/(tot-1);
				sm[i]++;
				if(p1>=0&&p2>=0)
					ans+=p1*p2;
			}
		}
	printf("%.12lf",ans);
	return 0;
}