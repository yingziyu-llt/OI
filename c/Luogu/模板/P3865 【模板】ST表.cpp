#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define N 110000
#define M 110000
int n, m, l, r;
int a[N];
int f[N][22];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &f[i][0]);
	int mmax = log(n) / log(2);
	for (int j = 1; j <= mmax; j++)
	{
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &l, &r);
		int k = (int)(log(r - l + 1) / log(2));
		printf("%d\n", max(f[l][k], f[r - (1 << k) + 1][k]));
	}
	return 0;
}