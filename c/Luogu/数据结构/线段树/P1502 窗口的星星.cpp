#include <stdio.h>
#include <algorithm>
#include <string.h>
#define N 11000
using namespace std;
struct Point
{
	int light, id, now;
	bool fl;
} x[N << 1], y[N << 1];
int left[N << 1], right[N << 1];
bool cmp1(Point a, Point b)
{
	return a.now < b.now;
}
bool cmp2(Point a, Point b)
{
	if (a.now == b.now)
		return a.light > b.light;
	return a.now < b.now;
}
struct segment_tree
{
	int lazy[N << 3], date[N << 3];
	void build(int now, int l, int r)
	{
		date[now] = lazy[now] = 0;
		int mid = (l + r) >> 1;
		if (l == r)
			return;
		build(now << 1, l, mid);
		build(now << 1 | 1, mid + 1, r);
		return;
	}
	void push_down(int now)
	{
		if (lazy[now] == 0)
			return;
		date[now << 1] += lazy[now];
		date[now << 1 | 1] += lazy[now];
		lazy[now << 1] += lazy[now];
		lazy[now << 1 | 1] += lazy[now];
		lazy[now] = 0;
	}
	void change(int now, int l, int r, int x, int y, int c)
	{
		if (x <= l && y >= r)
		{
			date[now] += c;
			lazy[now] += c;
			return;
		}
		push_down(now);
		int mid = (l + r) >> 1;
		if (x <= mid)
			change(now << 1, l, mid, x, y, c);
		if (y > mid)
			change(now << 1 | 1, mid + 1, r, x, y, c);
		date[now] = max(date[now << 1], date[now << 1 | 1]);
		return;
	}
	int query(int now, int l, int r, int x, int y)
	{
		if (x <= l && y >= r)
			return date[now];
		push_down(now);
		int res1 = 0, res2 = 0;
		int mid = (l + r) >> 1;
		if (x <= mid)
			res1 = query(now << 1, l, mid, x, y);
		if (y > r)
			res2 = query(now << 1 | 1, mid + 1, r, x, y);
		return max(res1, res2);
	}
} Tree;

int main()
{
	int cnt;
	scanf("%d", &cnt);
	while (cnt--)
	{
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(left, 0, sizeof(left));
		memset(right, 0, sizeof(right));
		int n, w, h;
		scanf("%d%d%d", &n, &w, &h);
		w -= 1;
		h -= 1;
		Tree.build(1, 1, n * 2);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &x[i].now, &y[i].now, &x[i].light);
			y[i].light = x[i].light;
			y[i].id = x[i].id = i;
			x[i].fl = y[i].fl = false;
		}
		//离散化
		for (int i = 1; i <= n; i++)
		{
			x[i + n] = x[i];
			x[i + n].now += w;
			x[i + n].fl = true;
		}
		sort(x + 1, x + n + n + 1, cmp1);
		int xcnt = 0;
		for (int i = 1; i <= n * 2; i++)
		{
			if (x[i].now != x[i - 1].now || i == 1)
				xcnt++;
			if (!x[i].fl)
				left[x[i].id] = xcnt;
			else
				right[x[i].id] = xcnt;
		}
		for (int i = 1; i <= n; i++)
		{
			y[i + n] = y[i];
			y[i + n].light = -y[i].light;
			y[i + n].now += h;
		}
		sort(y + 1, y + n + n + 1, cmp2);
		//扫描线
		int ans = 0;
		for (int i = 1; i <= 2 * n; i++)
		{
			if (y[i].light > 0)
			{
				int c = Tree.query(1, 1, xcnt, left[y[i].id], right[y[i].id]);
				if (ans < c + y[i].light)
				{
					ans = c + y[i].light;
				}
			}
			Tree.change(1, 1, xcnt, left[y[i].id], right[y[i].id], y[i].light);
		}
		printf("%d\n", ans);
	}
	return 0;
}