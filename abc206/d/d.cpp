#include<bits/stdc++.h>
using namespace std;
int n;
int s[200009];
int f[200009];
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=200000;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	for(int i=1;i<=n;i++)
	{
		int fa=fnd(s[i]),fb=fnd(s[n+1-i]);
		f[fa]=fb;
	}
	int ans=200000;
	for(int i=1;i<=200000;i++)
		if(fnd(i)==i)
			ans--;
	printf("%d",ans);
	return 0;
}