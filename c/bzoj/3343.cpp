#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int N = 1100000;
int n, m, nn;
int a[N], b[N], pos[N], tag[N];
int sq;
int reset(int x)
{
	int l = (x - 1) * sq, r = min(n, x * sq);
	for (int i = l; i <= r; i++)
		b[i] = a[i];
	sort(a + l, a + r + 1);
}
int change(int x, int y, int c)
{
	if (pos[x] == pos[y])
	{
		for (int i = x; i <= y; i++)
			a[i] += c;
		reset(pos[x]);
	}
	else
	{
		int t = min(pos[x] * sq, n);
		for (int i = x; i <= t; i++)
			a[x] += c;
		reset(pos[x]);
		for (int i = pos[x] + 1; i < pos[y]; i++)
			tag[i] += c;
		t = (pos[y] - 1) * sq + 1;
		for (int i = t; i <= y; i++)
			a[i] += c;
		reset(pos[y]);
	}
}
int find(int x, int v)
{
	int l = (x - 1) * sq + 1, r = min(n, x * sq);
	return r - (lower_bound(b + l, b + r + 1, v) - b) + 1;
}
int query(int x, int y, int v)
{
	int res = 0;
	if (pos[x] == pos[y])
	{
		for (int i = x; i <= y; i++)
			if (a[i] + tag[pos[i]] >= v)
				res++;
	}
	else
	{
		int t = min(pos[x] * sq,n);
		for(int i = x;i <= t;i++)
		{
			if(a[i] + tag[pos[i]] >= v)
				res++;
		}
		for(int i = pos[x] + 1;i < pos[y];i++)
		{
			res += find(pos[i],v);
		}
		int t = (pos[y] - 1) * sq;
		for(int i = t;i <= y;i++)
		{
			if(a[i] + tag[pos[i]] >= v)
				res++;
		}
	}
	return res;
}
int main()
{
	scanf("%d%d", &n, &m);
	sq = sqrt(n);
	if (n % sq)
		nn = n / sq;
	else
		nn = n / sq + 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
		pos[i] = (i - 1) / sq + 1;
	}
	for (int i = 1; i <= nn; i++)
		reset(i);
	for (int i = 1; i <= m; i++)
	{
		int x, y, c;
		char request;
		scanf("%c%d%d%d", &request, &x, &y, &c);
	}
}
