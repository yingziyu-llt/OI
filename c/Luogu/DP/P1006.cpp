#include<stdio.h>
#include<algorithm>
using namespace std;

const int N = 60,M = 60;
int f[N][N][N][N],map[N][M];
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			for(int k = 1;k <= m;k++)
			{
				for(int l = j + 1;l <= n;l++)
				{
					f[i][j][k][l] = max(f[i][j - 1][k - 1][l],max(f[i - 1][j][k][l - 1],max(f[i][j - 1][k][l - 1],f[i - 1][j][k - 1][l]))) + map[i][j] + map[k][l];
				}
			}
		}
	}
	printf("%d",f[n][m - 1][n - 1][m]);
	return 0;
}