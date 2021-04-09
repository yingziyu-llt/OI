#include<stdio.h>
#include<algorithm>
const int INF = 0x7fffffff;
using namespace std;
double dis[400][400];
double f[400][400][2];
int c[400],d[400];
double k[400];
int main()
{
	int n,m,v,e;
	scanf("%d%d%d%d",&n,&m,&v,&e);
	for(int i = 1;i <= n;i++)
		scanf("%d",&c[i]);
	for(int i = 1;i <= n;i++)
		scanf("%d",&d[i]);
	for(int i = 1;i <= n;i++)
		scanf("%lf",&k[i]);
	for(int i = 0;i <= n;i++)
	{
		for(int j = 0;j <= n;j++)
		{
			if(i == j) continue;
			dis[i][j] = INF;
		}
	}
	for(int i = 1;i <= e;i++)
	{
		int a,b;
		double w;
		scanf("%d%d%lf",&a,&b,&w);
		dis[a][b] = min(w,dis[a][b]);
		dis[b][a] = min(w,dis[b][a]);
	}
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				dis[i][j] = min(dis[i][j] ,dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			f[i][j][0] = min(f[i - 1][j][0] + dis[c[i - 1]][c[i]],f[i - 1][j][1] + dis[c[i - 1]][c[i]] * (1 - k[i - 1]) + dis[d[i - 1]][c[i]] *k[i - 1]);
			f[i][j][1] = min(f[i - 1][j][0] + dis[c[i - 1]][c[i]] * (1 - k[i]) + dis[c[i - 1]][d[i]] * k[i],f[i - 1][j - 1][1] + dis[c[i - 1]][c[i]] * (1 - k[i]) * (1 - k[i - 1]) + dis[d[i - 1]][c[i]] * k[i - 1] * (1 - k[i]) + dis[c[i - 1]][d[i]] * (1 - k[i - 1]) * k[i] + dis[d[i - 1]][d[i]] * k[i - 1] * k[i]); 
		}
	}
	double ans = INF;
	for(int i = 0;i <= m;i++) ans = min(ans,min(f[n][i][0],f[n][i][1]));
	printf("%.2lf",ans);
	return 0;
}