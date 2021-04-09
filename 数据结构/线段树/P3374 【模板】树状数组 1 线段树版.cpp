#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct segment_tree
{
	segment_tree *lson, *rson;
	int date;
} * root;

int a[500010],n;

void change(segment_tree *root, int l, int r, int x, int c)
{
	if (l == r)
	{
		root->date += c;
		return;
	}
	int mid = (l + r) >> 1;
	if (x > mid)
		change(root->rson, mid + 1, r, x, c);
	else
		change(root->lson, l, mid, x, c);
	root->date = root->lson->date + root->rson->date;
	return;
}

void build(segment_tree *root, int l, int r)
{
	if (l >= r)
	{
		root->date = a[l];
	}
	else
	{
		root->lson = new segment_tree;
		root->rson = new segment_tree;
		int mid = (l + r) >> 1;
		build(root->lson, l, mid);
		build(root->rson, mid + 1, r);
		root->date = root->lson->date + root->rson->date;
	}
}

int query(segment_tree *root, int l, int r, int x, int y)
{
	int mid = (l + r) >> 1,res1 = 0,res2 = 0;
	if(l >= x && y >= r) 
		return root->date;
	if(x <= mid)
		res1 = query(root->lson,l,mid,x,y);
	if(y > mid)
		res2 = query(root->rson,mid + 1,r,x,y);
	return res1 + res2;
}

int main()
{
	int m;
	root = new segment_tree;
	scanf("%d%d",&n,&m);
	for(int i = 1 ;i <= n;i++)
		scanf("%d",&a[i]);
	build(root,1,n);
	for(int i = 0;i < m;i++)
	{
		int commond,x,y;
		scanf("%d%d%d",&commond,&x,&y);
		if(commond == 1) change(root,1,n,x,y);
		else             printf("%d\n",query(root,1,n,x,y));
	}
	return 0;
}