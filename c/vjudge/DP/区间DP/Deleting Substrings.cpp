#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int INF = 1e9 + 10;
int v[410],f[410][410],w[410],g[410][410],h[410][410];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&v[i]);
	for(int i = 1;i <= n;i++) scanf("%d",&w[i]);
	for(int i = 1;i <= n;i++)
		f[i][i] = v[1],g[i][i] = h[i][i] = 0;
	for(int len = 2;len <= n;len++)
	{
		for(int i = 1;i + len - 1 <= n;i++)
		{
			int j = i + len - 1;
			g[i][j] = - INF;
			h[i][j] = - INF;
			for(int k = i + 1;k <= j;k++)
			{
				if(w[k] == w[i] + 1) g[i][j] = max(g[i][j],g[k][j] + f[i + 1][k - 1]);
				if(w[k] == w[i] - 1) h[i][j] = max(h[i][j],h[k][j] + f[i + 1][k - 1]);
			}
			f[i][j] = -INF;
			for(int k = i;k <= j;k++)
			{
				f[i][j] = max(f[i][j],f[i][k] + f[k + 1][j]);
				if(w[k] * 2 - w[i] - w[j] + 1 <= n && w[k] >= w[i] && w[k] >= w[j])
					f[i][j] = max(f[i][j],g[i][k] + h[k][j] + v[w[k] * 2 - w[i] - w[j] + 1]);
			}
		}
	}
	int ans[410];
	ans[0] = 0;
	for(int i = 1;i <= n;i++)
	{
		ans[i] = ans[i - 1];
		for(int j = 1;j <= i;j++)
			ans[i] = max(ans[i],ans[j - 1] + f[j][i]);
	}
	printf("%d",ans[n]);
	return 0;
}