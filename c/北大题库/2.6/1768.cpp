#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 110;
int f[N][N],sum[N][N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			scanf("%d",&f[i][j]);
			sum[i][j] = f[i][j] + sum[i - 1][j];
		}
	}
	int ans = -2147483647;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			int t = 0;
			for(int k = 1;k <= n;k++)
			{ 
				t += sum[j][k] - sum[i - 1][k];
				ans = max(ans,t);
				t = max(t,0);
			}
		}
	}
	printf("%d",ans);
	return 0;
}