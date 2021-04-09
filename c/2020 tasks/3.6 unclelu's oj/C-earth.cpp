#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;

struct edge
{
	int to,nxt,val;
}e[10000];
int ehead[10000],ecnt;
void addedge(int from,int to,int val)
{
	ecnt++;
	e[ecnt] = {to,ehead[from],val};
	ehead[from] = ecnt;
}

queue <int> q;
bool inque[10010];
int dist[10010];
int n,m;
bool vis[10010];bool can[10010];
void dfscan(int k)
{
	vis[k] = true;
	for(int i = ehead[k];i;i = e[i].nxt)
	{
		int to = e[i].to;
		if(vis[to]) continue;
		dfscan(to);
	}
	return ;
}
bool dfs(int u,int val)
{
	vis[u] = true;
	for(int i = ehead[u];i;i = e[i].nxt)
	{
		if(dist[u] + e[i].val + val < dist[e[i].to] && can[e[i].to])
		{
			if(vis[e[i].to]) return false;
			dist[e[i].to] = dist[u] + e[i].val + val;
			if(!dfs(e[i].to,val)) return false;
		}
	}
	vis[u] = false;
	return true;
}
void SPFA(int val)
{
	memset(inque,0,sizeof(inque));
	memset(dist,0x3f,sizeof(dist));
	q.push(1);
	inque[1] = true;
	dist[1] = 0;
	while(!q.empty())
	{
		int fr = q.front();
		q.pop();
		inque[fr] = false;
		for(int i = ehead[fr];i;i = e[i].nxt)
		{
			if(dist[fr] + e[i].val + val < dist[e[i].to] && can[e[i].to])
			{
				dist[e[i].to] = dist[fr] + e[i].val + val;
				if(!inque[e[i].to]) q.push(e[i].to),inque[e[i].to] = true;
			}
		}
	}
}
bool check(int m)
{
	for(int i = 1;i <= n;i++)
	{
		if(!can[i]) continue;
		memset(dist,0x3f,sizeof(dist));
		memset(vis,false,sizeof(vis));
		if(!dfs(i,m)) return false;
	}
	SPFA(m);
	if(dist[n] >= 0 && dist[n] != 0x3f3f3f3f) return true;
	else return false;
}


int main()
{
	//freopen("earth.in","r",stdin);
	//freopen("earth.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		ecnt = 0;
		memset(ehead,0,sizeof(ehead));
		memset(can,1,sizeof(can));
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= m;i++)
		{
			int from,to,val;
			scanf("%d%d%d",&from,&to,&val);
			addedge(from,to,val);
		}
		dfscan(1);
		for(int i = 1;i <= n;i++)
			if(!vis[i])
				can[i] = true;
		for(int i = 1;i <= n;i++)
		{
			if(!vis[i]) continue;
			memset(vis,0,sizeof(vis));
			dfscan(i);
			if(!vis[n])
				can[i] = false;
		}
		int l = -1e5,r = 1e5;
		int ans = -1;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if(check(mid)) ans = dist[n],r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}