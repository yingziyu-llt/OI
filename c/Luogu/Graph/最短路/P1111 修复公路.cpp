#include <stdio.h>
#include <algorithm>
using namespace std;
int fa[1011];
int n, m, tot = 1;
int ans = 0;
struct endg
{
	int fir, lat, val;
} e[100010];
bool cmp(endg a, endg b)
{
	return a.val < b.val;
}
int findfather(int x)
{
	return fa[x] = x == fa[x] ? x : findfather(fa[x]);
}
bool check()
{
	int f = findfather(1);
	for (int i = 2; i <= n; i++)
		if (findfather(i) != f)
			return false;
}
int main()
{

	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &e[i].fir, &e[i].lat, &e[i].val);
	}
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i++)
	{
		int fa1 = findfather(e[i].fir), fa2 = findfather(e[i].lat);
		if (fa1 != fa2)
		{
			ans = e[i].val;
			fa[fa1] = fa2;
			tot++;
		}
	}
	if (tot < n)
		printf("-1");
	else
		printf("%d", ans);
	return 0;
}
