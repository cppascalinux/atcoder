#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e18;
struct node
{
	int x;
	ll f;
	bool operator<(const node &p)const{return x<p.x;}
};
int n;
vector<node> vs[200009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		vs[b].push_back(node{a,inf});
	}
	vs[0].push_back(node{0,0});
	int ls=0;
	vs[n+1].push_back(node{0,inf});
	for(int i=1;i<=n+1;i++)
		if(vs[i].size())
		{
			sort(vs[i].begin(),vs[i].end());
			ll fx=vs[i].begin()->x,bx=vs[i].rbegin()->x;
			node bst{0,inf};
			int lp=-1;
			for(node &t:vs[i])
			{
				while(lp+1<vs[ls].size()&&vs[ls][lp+1].x<t.x)
				{
					lp++;
					ll nf=(ll)bx-fx+(bx-t.x)+abs(vs[ls][lp].x-fx)+vs[ls][lp].f;
					ll bf=(ll)bx-fx+(bx-t.x)+abs(bst.x-fx)+bst.f;
					if(nf<bf)
						bst=vs[ls][lp];
				}
				ll bf=(ll)bx-fx+(bx-t.x)+abs(bst.x-fx)+bst.f;
				t.f=min(t.f,bf);
			}
			reverse(vs[i].begin(),vs[i].end());
			reverse(vs[ls].begin(),vs[ls].end());
			lp=-1;
			bst={0,inf};
			for(node &t:vs[i])
			{
				while(lp+1<vs[ls].size()&&vs[ls][lp+1].x>t.x)
				{
					lp++;
					ll nf=(ll)bx-fx+(t.x-fx)+abs(vs[ls][lp].x-bx)+vs[ls][lp].f;
					ll bf=(ll)bx-fx+(t.x-fx)+abs(bst.x-bx)+bst.f;
					if(nf<bf)
						bst=vs[ls][lp];
				}
				ll bf=(ll)bx-fx+(t.x-fx)+abs(bst.x-bx)+bst.f;
				// printf("i:%d lp:%d bf:%lld\n",i,lp,bf);
				t.f=min(t.f,bf);
			}
			reverse(vs[i].begin(),vs[i].end());
			reverse(vs[lp].begin(),vs[lp].end());
			// for(node t:vs[i])
			// 	printf("i:%d x:%d f:%lld fx:%d bx:%d\n",i,t.x,t.f,fx,bx);
			ls=i;
		}
	for(node t:vs[n+1])
		printf("%lld",t.f);
	return 0;
}