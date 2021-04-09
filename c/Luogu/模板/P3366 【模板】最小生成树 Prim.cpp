#include<stdio.h>
#include<algorithm>
#include<queue>
#define INF 0x3fffffff
using namespace std;
priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
int n,m;
struct edge
{
	int to,next,val;
}e[10010];
int head[10010],ecnt;
void add_edge(int now,int to,int val)
{
	ecnt++;
	e[ecnt].to = to;
	e[ecnt].val = val;
	e[ecnt].next = head[now];
	head[now] = ecnt;
}

bool vis[10010];
int dis[10010];
int tot = 0;
void prim()
{
	for(int i = 1;i < n;i++)
		dis[i] = INF;
	for(int i = head[1];i;i = e[i].next)
		dis[e[i].to] = min(dis[e[i].to],e[i].val);
	dis[0] = 0;
	q.push(make_pair(0,1));
	vis[0] = true;
	while(!q.empty() && tot < n)
	{
		int 
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++)
	{
		break;
	}
}