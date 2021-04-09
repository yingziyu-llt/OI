//非tarjan缩点 TarjanLCA
#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 510000,M = 510000;
struct edge
{
	int to,nxt;
}e[N << 1];
int ehead[N],ecnt;
void addEdge(int from,int to)
{
	e[++ecnt].nxt = ehead[from];
	ehead[from] = ecnt;
	e[ecnt].to = to;
	return ;
}
struct query
{
	int from,to,nxt;
}q[M << 1];
int qhead[M << 1],qcnt;
void addQuery(int from,int to)
{
	q[++qcnt].from = from;
	q[qcnt].to = to;
	q[qcnt].nxt = qhead[from];
	qhead[from] = qcnt;
	return ;
}
int fa[N];
int getfa(int x)
{
	return fa[x] = fa[x] == x ? x : getfa(fa[x]);
}
bool vis[N];
int lca[M << 2];
int Tarjan(int root)
{
	fa[root] = root;
	vis[root] = true;
	for(int i = ehead[root];i;i = e[i].nxt)
	{
		if(vis[e[root].to]) continue;
		Tarjan(e[root].to);
		fa[e[root].to] = root;
	}
	for(int i = qhead[root];i;i = q[i].nxt)
	{
		int to = q[i].from == root ? q[i].to : q[i].from;
		if(vis[to])
			lca[i >> 1] = getfa(fa[to]);
	}
}

int main()
{
	int n,m,root;
	scanf("%d%d%d",&n,&m,&root);
	for(int i = 1;i < n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addEdge(x,y);
		addEdge(y,x);
	}
	for(int i = 0;i < m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addQuery(x,y);
		addQuery(y,x);
	}
	Tarjan(root);
	for(int i = 0;i < m;i++)
		printf("%d\n",lca[i]);
	return 0;
}