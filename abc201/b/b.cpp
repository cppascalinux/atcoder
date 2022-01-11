#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string t;
	map<int,string> mp;
	for(int i=1;i<=n;i++)
	{
		string s;
		int a;
		cin>>s>>a;
		mp[a]=s;
	}
	auto it=mp.end();
	it--,it--;
	cout<<it->second;
	return 0;
}