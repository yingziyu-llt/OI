#include <stdio.h>
#include <algorithm>
using namespace std;
struct aa
{
	int s, e;
} a[10000010];
bool cmp(aa a, aa b)
{
	return a.e < b.e;
}
int main()
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	int n, c = 1, end = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].s, &a[i].e);
		if (a[i].s > a[i].e)
			swap(a[i].s, a[i].e);
	}
	sort(a, a + n, cmp);
	end = a[0].e;
	for (int i = 0; i < n; i++)
	{
		if (a[i].s >= end)
		{
			end = a[i].e;
			c++;
		}
	}
	printf("%d", c);
	return 0;
}