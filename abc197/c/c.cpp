#include<bits/stdc++.h>
using namespace std;
int n;
int v[30];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",v+i);
	int mn=0x7FFFFFFF;
	for(int s=0;s<(1<<(n-1));s++)
	{
		int sm=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			int fg=0;
			if(i>1)
				fg=(s>>(i-2))&1;
			if(fg)
			{
				ans^=sm;
				sm=0;
			}
			sm|=v[i];
		}
		ans^=sm;
		if(ans<mn)
			mn=ans;
	}
	printf("%d",mn);
	return 0;
}