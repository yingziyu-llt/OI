#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
#define N 110000
#define K 110000
struct edge
{
	int to, val, nxt;
} e[N * 3];
int ehead[N], ecnt, n, k;
void addadge(int form, int to, int val)
{
	ecnt++;
	e[ecnt].to = to;
	e[ecnt].val = val;
	e[ecnt].nxt = ehead[form];
	ehead[form] = ecnt;
}

queue<int> q;
int dis[N];
bool vis[N];
int num[N];
bool SPFA()
{
	memset(dis, -1, sizeof(dis));
	dis[0] = 0;
	q.push(0);
	vis[0] = true;
	num[0] = 1;
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		vis[top] = false;
		for (int i = ehead[top]; i; i = e[i].nxt)
		{
			if (dis[e[i].to] < dis[top] + e[i].val)
			{
				dis[e[i].to] = dis[top] + e[i].val;
				if (!vis[e[i].to])
				{
					++num[e[i].to];
					if (num[e[i].to] >= n)
						return 0;
					q.push(e[i].to);
					vis[e[i].to] = 1;
				}
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++)
	{
		int x, y, k;
		scanf("%d%d%d", &k, &x, &y);
		if (k == 1)
			addadge(x, y, 0), addadge(y, x, 0);
		else if (k == 2)
		{
			if (x == y)
			{
				printf("-1");
				return 0;
			}
			addadge(x, y, 1);
		}
		else if (k == 3)
			addadge(y, x, 0);
		else if (k == 4)
		{
			if (x == y)
			{
				printf("-1");
				return 0;
			}
			addadge(y, x, 1);
		}
		else
			addadge(x, y, 0);
	}
	for(int i = n;i > 0;i--)
		addadge(0,i,1);
	if (!SPFA())
		printf("-1");
	else
	{
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			ans += dis[i];
		printf("%lld", ans);
	}
	return 0;
}