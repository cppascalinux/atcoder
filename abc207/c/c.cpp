#include<bits/stdc++.h>
using namespace std;
int n;
int typ[2009];
double l[2009],r[2009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%lf%lf",typ+i,l+i,r+i);
		if(typ[i]==2)
			r[i]-=0.1;
		else if(typ[i]==3)
			l[i]+=0.1;
		else if(typ[i]==4)
			r[i]-=0.1,l[i]+=0.1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(r[i]>=l[j]&&r[j]>=l[i])
				ans++;
		}
	printf("%d\n",ans);
	return 0;
}