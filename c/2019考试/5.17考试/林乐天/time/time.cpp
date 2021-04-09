#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 1100000;
long long a[N];
struct segment_tree
{
	long long date[N << 2], lazy[N << 2];
	void push_up(long long now)
	{
		date[now] = date[now << 1] + date[now << 1 | 1];
	}
	void build(long long now, long long l, long long r)
	{
		date[now] = 0;
		lazy[now] = 0;
		if (l >= r)
		{
			date[now] = a[l];
			lazy[now] = a[l];
			return;
		}
		long long mid = (l + r) >> 1;
		build(now << 1, l, mid);
		build(now << 1 | 1, mid + 1, r);
		push_up(now);
		return;
	}
	void push_down(long long now, long long l, long long r)
	{
		if (lazy[now] == 0)
			return;
		long long mid = (l + r) >> 1;
		date[now << 1] = lazy[now] * (mid - l + 1);
		date[now << 1 | 1] = lazy[now] * (r - mid);
		lazy[now << 1] = lazy[now];
		lazy[now << 1 | 1] = lazy[now];
		lazy[now] = 0;
	}
	void change(long long now, long long l,long long r,long long x,long long y,long long k)
	{
		if(x <= l && y >= r)
		{
			date[now] = k * (r - l + 1);
			lazy[now] = k;
			return;
		}
		lazy[now] = k;
		push_down(now,l,r);
		int mid = (l + r) >> 1;
		if(x <= mid)
			change(now << 1,l,mid,x,y,k);
		if(y > mid)
			change(now << 1 | 1,mid + 1,r,x,y,k);
		push_up(now);
		return ;
	}
	long long query(long long now, long long l, long long r, long long x, long long y)
	{
		if (x <= l && y >= r)
		{
			return date[now];
		}
		long long mid = (l + r) >> 1, res1 = 0, res2 = 0;
		if (x <= mid)
			res1 = query(now << 1, l, mid, x, y);
		if (mid < y)
			res2 = query(now << 1 | 1, mid + 1, r, x, y);
		return res1 + res2;
	}
} Tree;
int main()
{
	freopen("time.in","r",stdin);
	freopen("time.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	Tree.build(1,1,n);
	for(int i = 1;i <= m;i++)
	{
		int op;
		scanf("%d",&op);
		if(op == 1)
		{
			long long l,r,k;
			scanf("%lld%lld%lld",&l,&r,&k);
			Tree.change(1,1,n,l,r,k);
		}
		if(op == 2)
		{
			long long l,r;
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",Tree.query(1,1,n,l,r));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
