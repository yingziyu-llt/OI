#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int INF = 0x3fffffff;
int n,m,p[110],f[110][110],pre[110];
char a[2100];
int main()
{
	int T;
	scanf("%d\n",&T);
	for(int _i = 1;_i <= T;_i++)
	{
		int n;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++)
			scanf("%d",&p[i]);
		memset(f,0x3f,sizeof(f));
		memset(pre,0,sizeof(pre));
		for(int i = 1;i <= n;i++)
			pre[i] = pre[i - 1] + p[i];
		for(int i = 1;i <= n;i++) f[i][i] = f[i + 1][i] = 0;
		for(int l = 2;l <= n;l++)
		{
			for(int i = 1;i + l - 1 <= n;i++)
			{
				int j = i + l - 1;
				for(int k = i;k <= j;k++)
					f[i][j] = min(f[i][j],f[i + 1][k] + p[i] * (k - i) + f[k + 1][j] + (pre[j] - pre[k]) * (k - i + 1));
			}
		}
		printf("Case #%d: %d\n",_i,f[1][n]);	
	}
	return 0;
}