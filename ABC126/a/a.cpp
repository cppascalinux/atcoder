#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
char s[100];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	s[k]+='a'-'A';
	printf("%s",s+1);
	return 0;
}