#include<stdio.h>
#define N 1000000
double a[N];
struct segment_tree
{
	double tot[N << 2],lazy[N << 2],square[N << 2];
	void push_up(int now)
	{
		tot[now] = tot[now << 1] + tot[now << 1 | 1];
		square[now] = square[now << 1] + square[now << 1 | 1];
	}
	void build(int now,int l,int r)
	{
		if(l == r)
		{
			tot[now] = a[l];
			square[now] = a[l] * a[l];
			return ;
		}
		int mid = (l + r) >> 1;
		build(now << 1,l,mid);
		build(now << 1 | 1,mid + 1,r);
		push_up(now);
		return ;
	}
	void push_down(int now,int l,int r)
	{
		if(lazy[now] == 0)
			return ;
		int mid = (l + r) >> 1;
		lazy[now << 1] += lazy[now];
		lazy[now << 1 | 1] += lazy[now];
		square[now << 1] += 2 * tot[now << 1] * lazy[now] + lazy[now] * lazy[now] * (mid - l + 1);
		square[now << 1 | 1] += 2 * tot[now << 1 | 1] * lazy[now] + lazy[now] * lazy[now] * (r - mid);
		tot[now << 1] += lazy[now] * (mid - l + 1);
		tot[now << 1 | 1] += lazy[now] * (r - mid);
		lazy[now] = 0;
		return ;
	}
	void change(int now,int l,int r,int x,int y,double c)
	{
		push_down(now,l,r);
		if(x <= l && y >= r)
		{
			square[now] += 2 * tot[now] * c + c * c * (r - l + 1);
			tot[now] += c * (r - l + 1);
			lazy[now] += c;
			return ;
		}
		
		int mid = (l + r) >> 1;
		if(x <= mid)
			change(now << 1,l,mid,x,y,c);
		if(y > mid)
			change(now << 1 | 1,mid + 1,r,x,y,c);
		push_up(now);
		return ;
	}
	double query_sum(int now,int l,int r,int x,int y)
	{
		push_down(now,l,r);
		if(x <= l && y >= r)
		{
			return tot[now];
		}
		int mid = (l + r) >> 1;
		double sum1 = 0,sum2 = 0;
		if(x <= mid)
			sum1 = query_sum(now << 1,l,mid,x,y);
		if(y > mid)
			sum2 = query_sum(now << 1 | 1,mid + 1,r,x,y);
		return sum1 + sum2;
	}
	double query_square(int now,int l,int r,int x,int y)
	{
		push_down(now,l,r);
		if(x <= l && y >= r)
		{
			return square[now];
		}
		int mid = (l + r) >> 1;
		int sum1 = 0,sum2 = 0;
		if(x <= mid)
			sum1 = query_square(now << 1,l,mid,x,y);
		if(y > mid)
			sum2 = query_square(now << 1 | 1,mid + 1,r,x,y);
		return sum1 + sum2;
	}
}Tree;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%lf",&a[i]);
	Tree.build(1,1,n);
	for(int i = 0;i < m;i++)
	{
		int command;
		scanf("%d",&command);
		if(command == 1)
		{
			int x,y;
			double c;
			scanf("%d%d%lf",&x,&y,&c);
			Tree.change(1,1,n,x,y,c);
		}
		else if(command == 2)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%.4lf\n",(double)Tree.query_sum(1,1,n,x,y) / (double) (y - x + 1));
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			double sum =	Tree.query_sum(1,1,n,x,y);
			double square = Tree.query_square(1,1,n,x,y);
			printf("%.4lf\n",(square / (double) (y - x + 1) - (sum / (double) (y - x + 1)) * (sum / (double) (y - x + 1))));
		}
	}
	return 0;
}