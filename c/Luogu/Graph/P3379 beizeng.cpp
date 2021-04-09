#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
const int N = 510000,M = 500000;
using namespace std;
int f[20][N],depth[N];
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

void pre(int root,int dep,int fa)
{
	depth[root] = dep;
	f[0][root] = fa;
	for(int i = ehead[root];i;i = e[i].nxt)
	{
		if(e[i].to != fa)
		{
			pre(e[i].to, dep + 1, root);
			f[0][e[i].to] = root;
		}
	}
	for(int i = 1;i < 20;i++)
	{
		f[i][root] = f[i - 1][f[i - 1][root]];
		if(depth[f[i][root]] == 0) return;
	}
}

int getfa(int a,int b)
{
	if(depth[a] > depth[b])
		swap(a,b);
	while(depth[a] != depth[b])
	{
		int i = 20;
		while(depth[f[i][b]] > depth[a])
		{
			i--;
		}
		b = f[i][b];
	}
	while(f[0][a] != f[0][b])
	{
		int i = 20;
		while(f[i][a] == f[i][b])
		{
			i--;
		}
		a = f[i][a],b = f[i][b];
	}
	return f[0][a];
}
int main()
{
	int n,m,rt;
	scanf("%d%d%d",&n,&m,&rt);
	for(int i = 1;i < n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addEdge(x,y);
		addEdge(y,x);
	}
	pre(rt,0,0);
	for(int i = 1;i <= m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",getfa(a,b));
	}
	return 0;
}