#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int f[110][110];
int a[110],b[110];
int main()
{
	int n,m,K,s;
	while(~scanf("%d%d%d%d",&n,&m,&K,&s))
	{
		for(int i = 1;i <= K;i++)
			scanf("%d%d",&a[i],&b[i]);
		memset(f,0,sizeof(f));
		int ans = -1;
		for(int i = 1;i <= K;i++)
		{
			for(int j = b[i];j <= m;j++)
			{
				for(int k = s;k >= 1;k--)
				{
					f[j][k] = max(f[j][k],f[j - b[i]][k - 1] + a[i]);
					if(f[j][k] >= n) ans = max(ans,m - j);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}