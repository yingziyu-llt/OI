#include <stdio.h>
#include <string.h>
long long c[1100][1100];
bool x[100];
long long calc_c(int a, int b)
{
	if (a == 0 || a == b || b == 0)
		return 1;
	return c[a][b] = c[b][a] = c[b][a] != 0 ? c[b][a] : ((c[a - 1][b - 1] == 0 ? calc_c(a - 1, b - 1) : c[a - 1][b - 1]) + (c[a][b - 1] == 0 ? calc_c(a, b - 1) : c[a][b - 1]));
}
int main()
{
	long long a, b, len = 0;
	scanf("%d%d", &a, &b);
	memset(x, 0, sizeof(x));
	a--;
	while (a)
	{
		x[len] = (a & 1);
		a >>= 1;
		len++;
	}
	long long ans = 0;
	for (int i = 1; i <= len - 1; i++)
	{
		for (int j = len / 2; j <= i; j++)
		{
			ans += calc_c(j, i);
		}
	}
	int c = len - 2;
	for(int i = len - 1;i >= 1;i--)
	{
		int cnt = 0;
		for(;x[c] != 0;c--);
		cnt = len - c;
		for(int j = (len + 1) / 2 - cnt - 1;j < i;j++)
		{
			ans += calc_c(j,i);
		}
	}
	long long tmp = ans;
	memset(x, 0, sizeof(x));
	len = 0;
	while (b)
	{
		x[len] = (b & 1);
		b >>= 1;
		len++;
	}
	ans = 0;
	for (int i = 1; i <= len - 1; i++)
	{
		for (int j = len / 2; j <= i; j++)
		{
			ans += calc_c(j, i);
		}
	}
	c = len - 2;
	for(int i = len - 1;i >= 1;i--)
	{
		int cnt = 0;
		for(;x[c] != 0;c--);
		cnt = len - c;
		for(int j = (len + 1) / 2 - cnt - 1;j < i;j++)
		{
			if(j >= i) break;
			ans += calc_c(j,i);
		}
	}
	printf("%lld",ans - tmp);
	return 0;
}




