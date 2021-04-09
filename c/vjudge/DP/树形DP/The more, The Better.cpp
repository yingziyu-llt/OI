#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

struct Edge
{
	int to,nxt,val;
}e[300];
int ehead[300],ecnt;
void addedge(int from,int to,int val)
{
	e[++ecnt] = (Edge){to,ehead[from],val};
	ehead[from] = ecnt;
	return ;
}

int w[300],f[300][300];
int n,m;

int dfs(int u)
{
	int tot = 1;
	for(int i = 1;i <= m;i++)
		f[u][i] = w[u];
	for(int i = ehead[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		tot += dfs(v);
		for(int j = min(m + 1,tot + 1);j;j--)
			for(int k = 1;k < j;k++)
				f[u][j] = max(f[u][j],f[u][j - k] + f[v][k]);
	}
	return tot;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		if(n == 0 && m == 0) break;
		memset(ehead,0,sizeof(ehead));
		ecnt = 0;
		memset(f,0,sizeof(f));
		for(int i = 1;i <= n ;i ++)
		{
			int x;
			scanf("%d%d",&x,&w[i]);
			addedge(x,i,0);
		}
		dfs(0);
		printf("%d\n",f[0][m + 1]);
	}
	return 0;
}