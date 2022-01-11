#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[10];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	int k1=0,k2=0;
	scanf("%s",s+1);
	for(int i=1;i<=4;i++)
		s[i]-='0';
	int sm1=s[1]*10+s[2],sm2=s[3]*10+s[4];
	if(sm1<=12&&sm1>=1)
		k1=1;
	if(sm2<=12&&sm2>=1)
		k2=1;
	if(k1&&k2)
		printf("AMBIGUOUS");
	else if(k1&&!k2)
		printf("MMYY");
	else if(!k1&&k2)
		printf("YYMM");
	else
		printf("NA");
	return 0;
}