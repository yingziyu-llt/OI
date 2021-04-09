#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct edge
{
	int to,nxt,val;
}e[20010];
int ehead[10010],ecnt;
void addedge(int f,int t,int val)
{
	ecnt++;
	e[ecnt].to = t;
	e[ecnt].nxt = ehead[f];
	e[ecnt].val = val;
	ehead[f] = ecnt;
}
int f[10010][3];
int dfs1(int u,int fa)
{
	f[u][0] = f[u][1] = 0;
	for(int i = ehead[u];i;i = e[i].nxt)
	{
		if(e[i].to == fa) continue;
		int a1 = dfs1(e[i].to,u) + e[i].val;
		if(a1 > f[u][0])
		{
			f[u][1] = f[u][0];
			f[u][0] = a1;
		}
		else if(a1 > f[u][2]) f[u][2] = a1;
	}
	return f[u][0];
}
void dfs2(int u,int fa)
{
	for(int i = ehead[u];i;i = e[i].nxt)
	{
		if(e[i].to == fa) continue;
		int v = e[i].to;
		if(f[u][0] == f[v][0] + e[i].val) f[v][2] = max(f[u][1] ,f[u][2])+ e[i].val;
		else f[v][2] = max(f[u][0],f[u][2]) + e[i].val;
		dfs2(v,u);
	}
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(ehead,0,sizeof(ehead));
		ecnt = 0;
		for(int i = 2;i <= n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			addedge(i,a,b);
			addedge(a,i,b);
		}
		dfs1(1,0);
		dfs2(1,0);
		for(int i = 1;i <= n;i++)
			printf("%d\n",max(f[i][0],f[i][2]));
	}
	return 0;
}