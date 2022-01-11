#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	if(d*c-b>=1)
		printf("%lld\n",(a+(d*c-b)-1)/(d*c-b));
	else
		printf("-1\n");
	return 0;
}