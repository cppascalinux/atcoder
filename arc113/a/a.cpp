#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll f[200009];
int main()
{
	for(int i=1;i<=200000;i++)
		for(int j=1;j*j<=i;j++)
			if(i%j==0)
			{
				f[i]+=2;
				if(j*j==i)
					f[i]--;
			}
	// for(int i=1;i<=10;i++)
	// 	printf("i:%d f:%d\n",i,f[i]);
	for(int i=1;i<=200000;i++)
		f[i]+=f[i-1];
	int k;
	scanf("%d",&k);
	ll ans=0;
	for(int i=1;i<=k;i++)
		ans+=f[k/i];
	printf("%lld",ans);
	return 0;
}