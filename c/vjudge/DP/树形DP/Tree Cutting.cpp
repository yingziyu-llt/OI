#include<stdio.h>
#include<algorithm>
using namespace std;

int f[10010];
struct edge
{
	int to,nxt;
}e[20010];
int ehead[10010],ecnt;
void addedge(int f,int t)
{
	ecnt++;
	e[ecnt].to = t;
	e[ecnt].nxt = ehead[f];
	ehead[f] = ecnt;
}

int s,n;
int ans[10010],anscnt;
void dfs(int u,int fa)
{
	f[u] = 1;
	bool flag = true;
	for(int i = ehead[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v,u);
		f[u] += f[v];
		flag &= (f[v] <= s);
	}
	if(flag && n - f[u] <= s) ans[++anscnt] = u;
	return ;
}

int main()
{
	scanf("%d",&n);
	s = n / 2;
	for(int i = 1;i < n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		addedge(a,b);
		addedge(b,a);
	}
	dfs(1,0);
	sort(ans + 1,ans + anscnt + 1);
	if(anscnt == 0) printf("NONE");
	else
		for(int i = 1;i <= anscnt;i++)
			printf("%d\n",ans[i]);
	return 0;
}