#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 210;
int f[N][N];
int a[N];
int sum[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		a[i + n] = a[i];
	}
	for(int i = 1;i <= n * 2;i++)
		sum[i] = sum[i - 1] + a[i];
	for(int len = 1;len < n;len ++)
	{
		for(int i = 1 , j;i + len <= n * 2;i++)
		{
			j = i + len;
			f[i][j] = (1 << 28);
			for(int k = i;k < j;k++)
				f[i][j] = min(f[i][j] , f[i][k] + f[k + 1][j] +	sum[j] - sum[i - 1]);
		}
	}
	int ans = 1 << 28;
	for(int i = 1;i <= n + 1;i++)
		ans = min(f[i][i + n - 1],ans);
	printf("%d\n",ans);
	memset(f,0,sizeof(f));
	for(int len = 1;len < n;len++)
	{
		for(int i = 1,j;i + len <= n * 2;i++)
		{
			j = i + len;
			f[i][j] = 0;
			for(int k = i;k < j;k++)
				f[i][j] = max(f[i][j],f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);
		}
	}
	ans = 0;
	for(int i = 1;i <= n + 1;i++)
		ans = max(ans,f[i][i + n - 1]);
	printf("%d",ans);
	return 0;
}