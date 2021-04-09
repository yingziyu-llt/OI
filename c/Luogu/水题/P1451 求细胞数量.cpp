#include <stdio.h>
int a[200][200];
int f(int i, int j)
{
	if (a[i][j] != 0)
	{
		a[i][j] = 0;
		if (a[i + 1][j] != 0)
			f(i + 1, j);
		if (a[i][j + 1] != 0)
			f(i, j + 1);
		if (a[i][j - 1] != 0)
			f(i, j - 1);
		if (a[i - 1][j] != 0)
			f(i - 1, j);
	}
}
int main()
{
	int m, n, ans = 0;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
	{
		char s[10010];
		scanf("%s",s);
		for(int j = 0;j < strlen(s);j++)
		{
			a[i][j + 1] = (s[j] != '0')
		}
	}

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] != 0)
			{
				ans++;
				f(i, j);
			}
		}
	printf("%d", ans);
	return 0;
}