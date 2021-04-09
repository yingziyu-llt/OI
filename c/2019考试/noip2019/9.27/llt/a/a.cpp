#include <stdio.h>
#include <algorithm>
int aa[1000], bb[1000];
int bget[1000];
int n, m;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		bool flag = false;
		scanf("%d%d", &n, &m);
		int tot = 0, totx = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &aa[i]);
			if (aa[i] > m && !flag)
			{
				printf("No\n");
				flag = true;
			}
			tot += aa[i];
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &bb[i]);
			totx += bb[i];
		}
		if (totx < tot && !flag)
		{
			printf("No\n");
			flag = true;
		}
		if (!flag)
		{
			printf("Yes\n");
		}
	}
	return 0;
}