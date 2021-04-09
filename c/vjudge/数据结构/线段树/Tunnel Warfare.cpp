//区间合并
//HDU 1540/POJ 2892
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stack>
using namespace std;
const int N = 51000;
#define lson (root << 1)
#define rson (root << 1 | 1)

int n,m;
struct Segment_Tree
{
	int lq[N << 2],rq[N << 2],aq[N << 2];
	void pushup(int root,int l,int r)
	{
		int m = (l + r) / 2;
		lq[root] = lq[lson];
		rq[root] = rq[rson];
		int zy = max(lq[lson],rq[rson]);
		aq[root] = max(zy,rq[lson] + lq[rson]);
		if(lq[lson] == m - l + 1)
			lq[root] += lq[rson];
		if(rq[rson] == r - m)
			rq[root] += rq[lson];
	}
	void build(int root,int l,int r)
	{
		lq[root] = rq[root] = aq[root] = r - l + 1;
		if(l == r) return ;
		int mid = (l + r) / 2;
		build(lson,l,mid);
		build(rson,mid + 1,r);
		pushup(root,l,r);
		return ;
	}
	void change(int root,int p,int l,int r,int c)
	{
		if(l == r)
		{
			lq[root] = rq[root] = aq[root] = c;
			return ;
		}
		int mid = (l + r) / 2;
		if(p <= mid)
			change(lson,p,l,mid,c);
		else
			change(rson,p,mid + 1,r,c);
		pushup(root,l,r);
	}
	int quary(int root,int l,int r,int p)
	{
		if(aq[root] == r - l + 1 || aq[root] == 0 || l == r)
			return aq[root];
		int mid = (l + r) / 2;
		if(p <= mid)
		{
			if(p >= mid - rq[lson] + 1)
				return quary(lson,l,mid,p) + lq[rson];
			else
				return quary(lson,l,mid,p);
		}
		else
		{
			if(p <= mid + lq[rson])
				return quary(rson,mid + 1,r,p) + rq[lson];
			else
				return quary(rson,mid + 1,r,p);
		}
	}
}Tree;
stack <int> s;
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		char op[10];
		int a;
		Tree.build(1,1,n);
		for(int i = 0;i < m;i++)
		{
			scanf("%s",op);
			if(op[0] == 'R')
			{
				Tree.change(1,s.top(),1,n,1);
				s.pop();
				continue;
			}
			scanf("%d",&a);
			if(op[0] == 'Q')
				printf("%d\n",Tree.quary(1,1,n,a));
			else
			{
				Tree.change(1,a,1,n,0);
				s.push(a);
			}
		}
	}
	return 0;
}