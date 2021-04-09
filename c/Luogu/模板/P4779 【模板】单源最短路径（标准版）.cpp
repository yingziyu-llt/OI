#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

#define N 110000
#define M 510000
int m, n, s;

/***************************/
struct edge
{
	int to, nxt, val;
} e[M];
int ehead[N], ecnt;
void addedge(int u, int v, int w)
{
	ecnt++;
	e[ecnt].to = v;
	e[ecnt].val = w;
	e[ecnt].nxt = ehead[u];
	ehead[u] = ecnt;
}
/***************************/
struct node
{
	int pos, val;
	bool operator<(const node &a) const
	{
		return a.val < val;
	}
};

priority_queue <node> q;
/***************************/
bool vis[N];
int dis[N];
void dijkstra()
{
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	node now;
	now.pos = s;
	now.val = 0;
	q.push(now);
	while (!q.empty())
	{
		node tmp = q.top();
		q.pop();
		if (vis[tmp.pos])
			continue;
		vis[tmp.pos] = true;
		for (int i = ehead[tmp.pos]; i != 0; i = e[i].nxt)
		{
			int to = e[i].to;
			if (dis[to] > dis[tmp.pos] + e[i].val)
			{
				dis[to] = dis[tmp.pos] + e[i].val;
				now.pos = to;
				now.val = dis[to];
				q.push(now);
			}
		}
	}
	return;
}
/***************************************/
int main()
{
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= m; i++)
	{
		int u, v, val;
		scanf("%d%d%d", &u, &v, &val);
		addedge(u, v, val);
	}
	dijkstra();
	for (int i = 1; i <= n; i++)
	{
		if (dis[i] == 0x3f3f3f3f)
			printf("2147483647 ");
		else
			printf("%d ", dis[i]);
	}
	return 0;
}