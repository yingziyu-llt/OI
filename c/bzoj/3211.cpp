#include<stdio.h>
#include<string.h>
#include<math.h>
const int N = 110000;
long long a[N];
struct segment_tree
{
	long long date[N << 2],tag[N << 2];
	void pushup(int root)
	{
		date[root] = date[root << 1] + date[root << 1 | 1];
		tag[root] = tag[root << 1] & tag[root << 1 | 1];
		return ; 
	}
	void build(int root,int l,int r)
	{
		if(l == r)
		{
			date[root] = a[l];
			tag[root] = false;
			return ;
		}
		int mid = (l + r) >> 1;
		build(root << 1,l,mid);
		build(root << 1 | 1,mid + 1,r);
		pushup(root);
		return ;
	}
	void change(int root,int l,int r,int x,int y)
	{
		if(tag[root])
			return;
		if(l == r)
		{
			date[root] = (int)sqrt(date[root]);
			if(!date[root] || date[root] == 1) tag[root] = true;
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid) change(root << 1,l,mid,x,y);
		if(y > mid) change(root << 1 | 1,mid + 1,r,x,y);
		pushup(root);
		return ;
	}
	long long query(int root,int l,int r,int x,int y)
	{
		if (x <= l && y >= r)
		{
			return date[root];
		}
		long long ans = 0;
		int mid = (l + r) >> 1;
		if(x <= mid) ans += query(root << 1,l,mid,x,y);
		if(y > mid) ans += query(root << 1 | 1,mid + 1,r,x,y);
		return ans;
	}
	
}Tree;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	Tree.build(1,1,n);
	int T;
	scanf("%d",&T);
	for(int i = 0;i < T;i++)
	{
		int op;
		scanf("%d",&op);
		int l,r;
		scanf("%d%d",&l,&r);
		if(op == 1)
			printf("%lld\n",Tree.query(1,1,n,l,r));
		else
			Tree.change(1,1,n,l,r);
	}
	return 0;
}