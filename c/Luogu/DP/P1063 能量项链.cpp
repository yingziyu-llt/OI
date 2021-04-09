#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 110;
int a[N << 1];
int f[N << 1][N << 1];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]),a[i + n] = a[i];
	int maxn = 0;
	for(int len = 1;len <= n;len++)
	{
		for(int i = 1, j;i + len  <= n * 2;i++)
		{
			j = i + len;
			for(int k = i + 1;k < j;k++)
				f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[j] * a[k]);
		}
	}
	for(int i = 1;i <= n;i++)
		maxn = max(maxn ,f[i][i + n]);
	printf("%d",maxn);
	return 0;
}