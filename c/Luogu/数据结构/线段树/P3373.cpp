#include<stdio.h>
#include<algorithm>
using namespace std;
const long long N = 110000;
long long a[N];
long long P;
void modP(long long &a)
{
	a %= P;
}
struct segment_tree
{
	long long date[N << 2],lazy1[N << 2],lazy2[N << 2];
	void push_up(long long now)
	{
		date[now] = (date[now << 1] + date[now << 1 | 1]) % P;
	}
	void build(long long now,long long l,long long r)
	{
		if(l == r)
		{
			date[now] = a[l];
			lazy1[now] = 0;
			lazy2[now] = 1;
			return ;
		}
		long long mid = (l + r) >> 1;
		build(now << 1,l,mid);
		build(now << 1 | 1,mid + 1,r);
		lazy1[now] = 0;
		lazy2[now] = 1;
		push_up(now);
	}
	void push_down(long long now,long long l,long long r)
	{
		if(lazy1[now] == 0 && lazy2[now] == 1) return ;
		long long mid = (l + r) >> 1; 
		date[now << 1] *= lazy2[now];
		date[now << 1 | 1] *= lazy2[now];
		modP(date[now << 1]);
		modP(date[now << 1 | 1]);
		date[now << 1] += lazy1[now] * (mid - l + 1);
		date[now << 1 | 1] += lazy1[now] * (r - mid);
		modP(date[now << 1]);
		modP(date[now << 1 | 1]);
		lazy1[now << 1] *= lazy2[now];
		lazy1[now << 1 | 1] *= lazy2[now];
		modP(lazy1[now << 1]);
		modP(lazy1[now << 1 | 1]);
		lazy1[now << 1] += lazy1[now];
		lazy1[now << 1 | 1] += lazy1[now];
		modP(lazy1[now << 1]);
		modP(lazy1[now << 1 | 1]);
		lazy2[now << 1] *= lazy2[now];
		lazy2[now << 1 | 1] *= lazy2[now];
		modP(lazy2[now << 1]);
		modP(lazy2[now << 1 | 1]);
		lazy1[now] = 0;
		lazy2[now] = 1;
	}
	void change1(long long now,long long l,long long r,long long x,long long y,long long c)
	{
		if(x <= l && y >= r)
		{
			lazy1[now] += c;
			lazy1[now] %= P;
			date[now] += (r - l + 1) * c;
			date[now] %= P; 
			return ;
		}
		push_down(now,l,r);
		long long mid = (l + r) >> 1;
		if(x <= mid)
			change1(now << 1,l,mid,x,y,c);
		if(y > mid)
			change1(now << 1 | 1,mid + 1,r,x,y,c);
		push_up(now);
		return ;
	}
	void change2(long long now,long long l,long long r,long long x,long long y,long long c)
	{
		if(x <= l && y >= r)
		{
			lazy2[now] *= c;
			lazy2[now] %= P;
			date[now]  *= c;
			date[now]  %= P;
			lazy1[now] *= c;
			lazy1[now] %= P; 
			return ;
		}
		push_down(now,l,r);
		long long mid = (l + r) >> 1;
		if(x <= mid)
			change2(now << 1,l,mid,x,y,c);
		if(y > mid)
			change2(now << 1 | 1,mid + 1,r,x,y,c);
		push_up(now);
		return ;
	}
	long long query(long long now,long long l,long long r,long long x,long long y)
	{
		if(x <= l && y >= r)
			return date[now];
		push_down(now,l,r);
		long long mid = (l + r) >> 1,res1 = 0,res2 = 0;
		if(x <= mid)
			res1 = query(now << 1,l,mid,x,y);
		if(y > mid)
			res2 = query(now << 1 | 1,mid + 1,r,x,y);
		return (res1 + res2) % P;
	}
}Tree;
int main()
{
	long long n,m;
	scanf("%lld%lld%lld",&n,&m,&P);
	for(long long i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
	}
	Tree.build(1,1,n);
	for(long long i = 0; i < m;i++)
	{
		long long order;
		scanf("%lld",&order);
		if(order == 1)
		{
			long long x,y,k;
			scanf("%lld%lld%lld",&x,&y,&k);
			Tree.change2(1,1,n,x,y,k);
		}
		else if(order == 2)
		{
			long long x,y,k;
			scanf("%lld%lld%lld",&x,&y,&k);
			Tree.change1(1,1,n,x,y,k);
		}
		else
		{
			long long x,y;
			scanf("%lld%lld",&x,&y);
			printf("%d\n",Tree.query(1,1,n,x,y));
		}
	}
	return 0;
}