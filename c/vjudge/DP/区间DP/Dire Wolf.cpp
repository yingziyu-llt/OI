#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[210],b[210],f[210][210];
int main()
{
	int T;
	scanf("%d",&T);
	for(int _i = 1;_i <= T;_i++)
	{
		int n;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		for(int i = 1;i <= n;i++)
			scanf("%d",&b[i]);
		for(int l = 1;l <= n;l++)
		{
			for(int i = 1;i + l - 1 <= n;i++)
			{
				int j = i + l - 1;
				f[i][j] = 0x3fffffff;
				for(int k = i;k <= j;k++)
					f[i][j] = min(f[i][j],f[i][k - 1] + f[k + 1][j] + a[k] + b[i - 1] + b[j + 1]);
			}
		}
		printf("Case #%d: %d\n",_i,f[1][n]);
	}
	return 0;
}