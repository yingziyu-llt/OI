#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
bool ans[110000];
int x[110000][2];
int main()
{
	freopen("or.in","r",stdin);
	freopen("or.out","w",stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	memset(ans, 1, sizeof(ans));
	int j = -1;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (c)
		{
			x[++j][0] = a, x[j][1] = b;
		}
		else
		{
			for (int i = a; i <= b; i++)
			{
				ans[i] = 0;
			}
		}
	}
	bool flag = false, xx = false;
	for (; j >= 0; j--)
	{
		for (int i = x[j][0]; i <= x[j][1]; i++)
		{
			xx = xx | ans[i];
		}
		if (!xx)
		{
			flag = true;
			break;
		}
	}
	if (flag)
		printf("No");
	else
	{
		printf("Yes\n");
		for (int i = 0; i < n; i++)
		{
			printf("%d ",ans[i]);
		}
	}
	return 0;
}
