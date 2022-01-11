#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,w;
	scanf("%d%d%d",&a,&b,&w);
	w*=1000;
	if(w<a)
		return printf("UNSATISFIABLE"),0;
	int mn=1e9,mx=-1;
	for(int i=1;i<=w;i++)
	{
		if(i*a<=w&&i*b>=w)
			mn=min(mn,i),mx=max(mx,i);
	}
	if(mx==-1)
		printf("UNSATISFIABLE");
	else
		printf("%d %d",mn,mx);
	return 0;
}