#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		if(n%2!=0)
			printf("Odd\n");
		else if(n%2==0&&n%4!=0)
			printf("Same\n");
		else
			printf("Even\n");
	}
	return 0;
}