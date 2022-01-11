#include<bits/stdc++.h>
using namespace std;
int n;
int l[109],r[109];
int f[109][109];
int dp(int sl,int sr)
{
	if(f[sl][sr]>=0)
		return f[sl][sr];
	if(sl>sr)
		return f[sl][sr]=0;
	vector<int> v;
	for(int i=1;i<=n;i++)
		if(l[i]>=sl&&r[i]<=sr)
		{
			int sg=dp(sl,l[i]-1)^dp(r[i]+1,sr);
			// printf("sl:%d sr:%d i:%d sg:%d\n",sl,sr,i,sg);
			v.push_back(sg);
		}
	sort(v.begin(),v.end());
	int d=unique(v.begin(),v.end())-v.begin();
	// printf("d:%d\n",d);
	for(int i=0;i<d;i++)
		if(v[i]!=i)
			return f[sl][sr]=i;
	return f[sl][sr]=d;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",l+i,r+i),r[i]--;
		memset(f,-1,sizeof(f));
		printf("%s\n",dp(1,100)?"Alice":"Bob");
	}
	return 0;
}