#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 11000,M = 510000;
priority_queue <pair<int,int> > q;
struct edge
{
	int to,val,nxt;
}e[M];
int ehead[N],dis[N],eCnt;
void addEdge(int from,int to,int val)
{
	e[++eCnt].nxt = ehead[from];
	ehead[from] = eCnt;
	e[eCnt].to = to;
	e[eCnt].val = val;
}
bool vis[N];
void dijkstya(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s] = 0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int from = q.top().second;
		q.pop();
		vis[from] = true;
		for(int i = ehead[from];i ; i = e[i].nxt)
		{
			int to = e[i].to;
			if(dis[to] > dis[from] + e[i].val)
			{
				dis[to] = dis[from] + e[i].val;
				if(!vis[to]) q.push(make_pair(-dis[to],to));
			}
		}
	}
	return ;
}
int main()
{
	int m,n,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i = 1;i <= m;i++)
	{
		int from,to,val;
		scanf("%d%d%d",&from,&to,&val);
		addEdge(from,to,val);
	}
	dijkstya(s);
	for(int i = 1;i <= n;i++)
		printf("%d ",dis[i] == 0x3f3f3f3f ? 2147483647 : dis[i]);
	return 0;
}