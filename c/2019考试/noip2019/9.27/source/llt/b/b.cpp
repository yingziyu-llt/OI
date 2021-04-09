#include <stdio.h>
#include <algorithm>
int ina[10010];
bool put[10010];
int b[10010];
int x = 0, tot = 0;
int n;
void add(int a)
{
	if (a == n + 1)
	{
		x++;
		for (int i = 1; i <= n; i++)
		{
			tot += ina[i] * (int)(b[i - 1] < b[i] && b[i] > b[i + 1]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!put[i])
		{
			put[i] = true;
			b[i] = a;
			add(a + 1);
			put[i] = false;
			b[i] = 0;
		}
	}
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &ina[i]);
		}
		add(n);
		printf("%.3lf\n",(double)tot / (double)x);
	}
	return 0;
}