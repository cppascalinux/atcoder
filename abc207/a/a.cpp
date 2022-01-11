#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	printf("%d\n",a+b+c-min(a,min(b,c)));
	return 0;
}