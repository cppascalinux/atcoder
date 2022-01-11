#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	char s[1009];
	scanf("%s",s+1);
	int n=strlen(s+1);
	int fg=1;
	for(int i=1;i<=n;i+=2)
		if(!(s[i]>='a'&&s[i]<='z'))
			fg=0;
	for(int i=2;i<=n;i+=2)
		if(!(s[i]>='A'&&s[i]<='Z'))
			fg=0;
	printf("%s",fg?"Yes":"No");
	return 0;
}