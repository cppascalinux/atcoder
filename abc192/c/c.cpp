#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,k;
int g1(int x)
{
	vector<int> v;
	while(x)
	{
		v.push_back(x%10);
		x/=10;
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(int t:v)
		ans=ans*10+t;
	return ans;
}
int g2(int x)
{
	vector<int> v;
	while(x)
	{
		v.push_back(x%10);
		x/=10;
	}
	sort(v.begin(),v.end(),greater<int>());
	int ans=0;
	for(int t:v)
		ans=ans*10+t;
	return ans;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		n=g2(n)-g1(n);
	printf("%d",n);
	return 0;
}