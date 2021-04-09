#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 100005;

int pos[maxn],n,a[maxn];
namespace ST {
	#define ls rt<<1
	#define rs rt<<1|1
	int mx[maxn<<2];
	void build(int rt,int L,int R) {
		if (L>=R) {
			mx[rt]=a[L];return ;
		}
		int mid=L+R>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		mx[rt]=max(mx[ls],mx[rs]);
	}
	void assign0(int rt,int L,int R,int p) {
		if (L>=R) {
			mx[rt]=0;return ;
		}
		int mid=L+R>>1;
		if (p<=mid) assign0(ls,L,mid,p);
		else assign0(rs,mid+1,R,p);
		mx[rt]=max(mx[ls],mx[rs]);
	}
	int findl(int rt,int L,int R,int l) {
		if (!mx[rt]) return 0;
		if (l>R) return 0;
		if (L>=R) return L;
		int mid=L+R>>1,res;
		if (l<=mid&&(res=findl(ls,L,mid,l))) return res;
		return findl(rs,mid+1,R,l);
	}
	int findmx(int rt,int L,int R,int l,int r) {
		if (L>=l&&R<=r) return mx[rt];
		int mid=L+R>>1,res=0;
		if (l<=mid) res=max(res,findmx(ls,L,mid,l,r));
		if (r>mid) res=max(res,findmx(rs,mid+1,R,l,r));
		return res;
	}
}
using namespace ST;

int main()
{
	#ifndef ONLINE_JUDGE
		//freopen("wa.in","r",stdin);
		//freopen("wa.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),pos[a[i]]=i;
	build(1,1,n);
	for (int i=1;i<=n>>1;i++)
	{
		int p=pos[mx[1]],q=findl(1,1,n,p+1);
		if (!q) p=pos[findmx(1,1,n,1,p-1)],q=findl(1,1,n,p+1);
		assign0(1,1,n,p);assign0(1,1,n,q);
		printf("%d %d ",a[p],a[q]);
	}
	return 0;
}
