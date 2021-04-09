#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 1100000;
/****************************/
struct Edge
{
	int to,nxt;
}e[N << 1];
int eCnt = 1,eHead[N];
void addEdge(int from,int to)
{
	eCnt++;
	e[eCnt].nxt = eHead[from];
	e[eCnt].to = to;
	eHead[from] = eCnt;
}
/*****************************/
int n,from,to,cir_edge;
int fig[N];
long long f[N][2];
bool vis[N];
void findCir(int now,int fa)
{
	vis[now] = true;
	for(int i = eHead[now];i > 1;i = e[i].nxt)
	{
		if((i ^ 1) == fa)
			continue;
		if(vis[e[i].to])
		{
			from = now,to = e[i].to;
			cir_edge = i;
			continue;
		}
		findCir(e[i].to,i);
	}
}

void dfs(int now,int fa)
{
	f[now][0] = 0;
	f[now][1] = fig[now];
	for(int i = eHead[now];i > 1;i = e[i].nxt)
	{
		if((i ^ 1) == fa)
			continue;
		if(i == cir_edge || (i ^ 1) == cir_edge)
			continue;
		dfs(e[i].to,i);
		f[now][0] += max(f[e[i].to][0],f[e[i].to][1]);
		f[now][1] += f[e[i].to][0];
	}
}

int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n; i++)
	{
		int x;
		scanf("%d%d",&fig[i],&x);
		addEdge(x,i);
		addEdge(i,x);
	}
	long long ans = 0;
	for(int i = 1;i <= n;i++)
	{
		if(vis[i])
			continue;
		findCir(i,-2);
		dfs(from,-1);
		long long tmp = f[from][0];
		dfs(to,-1);
		tmp = max(f[to][0],tmp);
		ans += tmp;
	}
	printf("%lld",ans);
	return 0;
}