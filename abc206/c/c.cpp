#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int s[300009];
int main()
{
	map<int,int> mp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i),mp[s[i]]++;
	ll ans=(ll)n*(n+1)/2;
	for(auto t:mp)
		ans-=(ll)t.second*(t.second+1)/2;
	printf("%lld",ans);
	return 0;
}