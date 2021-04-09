#include <stdio.h>
#include <algorithm>
#include <string.h>
#define lson root << 1
#define rson root << 1 | 1
using namespace std;
const int N = 200000;
int a[N];
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int f[N << 2][2][2];
inline void push_up(int root, int l, int r)
{
	int mid = (l + r) >> 1;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			f[root][i][j] = max(f[lson][i][0] + max(f[rson][1][j], f[rson][0][j]), f[lson][i][1] + f[rson][0][j]);
}
inline void build(int root, int l, int r)
{
	if (l == r)
	{
		f[root][1][1] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	push_up(root, l, r);
	return;
}
inline void change(int root, int l, int r, int k, int x)
{
	if (l == r)
	{
		f[root][1][1] = x;
		return;
	}
	int mid = (l + r) >> 1;
	if (k <= mid)
		change(lson, l, mid, k, x);
	else
		change(rson, mid + 1, r, k, x);
	push_up(root, l, r);
}
int main()
{
	int n = 0, d;
	long long ans = 0;
	n = read(), d = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	build(1, 1, n);
	for (int j = 1; j <= d; j++)
	{
		int x, y;
		x = read(), y = read();
		change(1, 1, n, x, y);
		ans += max(max(f[1][1][1], f[1][0][1]), max(f[1][0][0], f[1][1][0]));
	}
	printf("%lld", ans);
	return 0;
}