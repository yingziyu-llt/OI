#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define LL long long
struct Edge
{
	int to,nxt,val;
}e[4400];
int ehead[2200],ecnt;
void addedge(int from,int to,int val)
{
	e[++ecnt] = (Edge){to,ehead[from],val};
	ehead[from] = ecnt;
	return ;
}

long long f[2200][2200],sum[2200];
int k,n,m;
void dfs(int u,int fa)
{
	sum[u] = 1;
	f[u][0] = f[u][1] = 0;
	for(int i = ehead[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v,u);
		sum[u] += sum[v];
		for(int j = sum[u];j >= 0;j--)
			for(int l = 0;l <= min(sum[v],(LL)j);l++)
				f[u][j] = max(f[u][j],f[u][j - l] + ((LL)l * (k - l) + (LL)(sum[v] - l) *(n - k - (sum[v] - l))) * e[i].val + f[v][l]);
	}
	return ;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i = 1;i < n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
		addedge(y,x,z);
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			f[i][j] = - 1e16 + 7;
	dfs(1,0);
	printf("%lld",f[1][k]);
	return 0;
}