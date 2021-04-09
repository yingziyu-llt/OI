#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

const int N = 210,M = 210;
int f[N][M];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			scanf("%d",&f[i][j]);
			f[i][j] += max(max(f[i - 1][j],f[i - 1][j - 1]),f[i - 1][j + 1]);
		}
	}
	printf("%d",max(f[n][m/2],max(f[n][m/2+1],f[n][m/2+2])));
	return 0;
}