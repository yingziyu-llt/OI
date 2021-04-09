#include<stdio.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
const int N = 200,M = 6100,INF = 0x7fffffff;
int n,m,ehead[N * 2],cnt,ind[N * 2],nxt[N];
bool vis[N];
queue <int> q;
struct edge
{
	int from,to,val,nxt;
}e[M * 2 + N * 4];
void addedge(int from,int to,int val)
{
	e[cnt] = {from,to,val,ehead[from]};
	ehead[from] = cnt;
	cnt++;
}
void bfs()
{
	while(!q.empty()) q.pop();
	memset(ind,0,sizeof(ind));
	q.push(0);
	ind[0] = 1;
	while(!q.empty())
	{
		int now = q.front();
		for(int i = ehead[now];i;i = e[i].nxt)
		{
			int to = e[i].to;
			if(ind[to] || e[i].val == 0) continue;
			ind[to] = ind[now] + 1;
			q.push(to);
		}
		q.pop();
	}
	return ;
}
int dfs(int now,int _min)
{
	if(now == n * 2 + 1) return _min;
	int ret = 0,k;
	for(int i = ehead[now];i;i = e[i].nxt)
	{
		int to = e[i].to;
		if(ind[to] != ind[now] + 1 || e[i].val == 0) continue;
		k = dfs(to,min(_min - ret,e[i].val));
		e[i].val -= k;
		e[i ^ 1].val += k;
		ret += k;
		if(ret == _min) break;
	}
	return ret;
}
int main()
{
	memset(ehead,-1,sizeof(ehead));
	scanf("%d%d",&n,&m);
	for(int i = 0;i < m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y + n,INF);
		addedge(y + n,x,0);
	}
	for(int i = 1;i <= n;i++)
	{
		addedge(0,i,1);
		addedge(i,0,0);
		addedge(i + n,n + n + 1,1);
		addedge(2 * n + 1,i + n,0);
	}
	int ans = 0;
	while(1)
	{
		bfs();
		if(!ind[2 * n + 1]) break;
		ans += dfs(0,INF);
	}
	for(int i = 0;i <= m * 2 - 1;i++)
		if(e[i ^ 1].val) nxt[e[i].from] = e[i].to - n;
	for(int i = 1;i <= n;i++)
	{
		if(!vis[i])
		{
			int j = i;
			vis[i] = true;
			printf("%d ",i);
			while(nxt[j])
			{
				printf("%d ",nxt[j]);
				j = nxt[j];
				vis[j] = true;
			}
			puts("");
		}
	}
	printf("%d",n - ans);
	return 0;
}