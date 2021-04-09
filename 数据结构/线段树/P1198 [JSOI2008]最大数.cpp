#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 210000;
const int INF = 2147483676;
int from[N],to[N],a[N],D;
struct segment_tree
{
	long long date[N << 2];
	void push_up(int now)
	{
		date[now] = max(date[now << 1],date[now << 1 | 1]);
	}
	void build(int now,int l,int r)
	{
		if(l == r)
		{
			date[now] = a[l];
			return ;
		}
		int mid = (l + r) >> 1;
		build(now << 1,l,mid);
		build(now << 1 | 1,mid + 1,r);
		push_up(now);
		return ;
	}
	long long query(int now,int l,int r,int x,int y)
	{
		if(x <= l && y >= r)
			return date[now];
		int mid = (l + r) >> 1,res1 = -INF,res2 = -INF;
		if(x <= mid)
			res1 = query(now << 1,l,mid,x,y);
		if(mid < y)
			res2 = query(now << 1 | 1,mid + 1,r,x,y);
		return max(res1,res2);
	}
}Tree;

int main()
{
	int m;
	scanf("%d%d",&m,&D);
	int n = 0,c = 0;
	for(int i = 1;i <= m;i++)
	{
		char order[10];
		scanf("%s",&order);
		if(order[0] == 'A')
		{
			n++;
			scanf("%d",&a[n]);
		}
		else
		{
			c++;
			int len;
			scanf("%d",&len);
			from[c] = n - len;
			to[c] = n;
		}
	}
	Tree.build(1,1,n);
	for(int i = 1;i <= c;i++)
	{
		printf("%lld\n",Tree.query(1,1,n,from[i],to[i]) % D);
	}
	return 0;
}
