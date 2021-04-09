#include <stdio.h>
struct segment_tree
{
	segment_tree *lson, *rson;
	long long lazy, date;
};
int a[100000];
void build(segment_tree *root, int l, int r)
{
	root->date = 0;
	root->lazy = 0;
	if (l >= r)
	{
		root->date = a[l];
		root->lazy = 0;
		return;
	}
	int mid = (l + r) >> 1;
	root->lson = new segment_tree;
	root->rson = new segment_tree;
	build(root->lson, l, mid);
	build(root->rson, mid + 1, r);
	root->date = root->lson->date + root->rson->date;
}
void pushdown(segment_tree *root, int l, int r)
{
	if (root->lazy == 0)
		return;
	int mid = (l + r) >> 1;
	root->lson->date += root->lazy * (mid - l + 1);
	root->rson->date += root->lazy * (r - mid);
	root->lson->lazy += root->lazy;
	root->rson->lazy += root->lazy;
	root->lazy = 0;
}
void change(segment_tree *root, int l, int r, int x, int y, long long c)
{
	if (x <= l && y >= r)
	{
		root->date += c * (r - l + 1);
		root->lazy += c;
		return;
	}
	pushdown(root, l, r);
	long long mid = (l + r) >> 1;
	if (x <= mid)
		change(root->lson, l, mid, x, y, c);
	if (y > mid)
		change(root->rson, mid + 1, r, x, y, c);
	root->date = root->lson->date + root->rson->date;
}
long long query(segment_tree *root, int l, int r, int x, int y)
{
	if (x <= l && y >= r)
	{
		return root->date;
	}
	pushdown(root, l, r);
	long long mid = (l + r) >> 1, res1 = 0, res2 = 0;
	if (x <= mid)
		res1 = query(root->lson, l, mid, x, y);
	if (y > mid)
		res2 = query(root->rson, mid + 1, r, x, y);
	return res1 + res2;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	segment_tree *root = new segment_tree;
	build(root, 1, n);
	for (int i = 0; i < m; i++)
	{
		int commond, x, y, k;
		scanf("%d", &commond);
		if (commond == 1)
		{
			scanf("%d%d%d", &x, &y, &k);
			change(root, 1, n, x, y, k);
		}
		else
		{
			scanf("%d%d", &x, &y);
			printf("%lld\n", query(root, 1, n, x, y));
		}
	}
	return 0;
}