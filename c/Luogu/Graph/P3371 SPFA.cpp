#include<string.h>
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 11000,M = 510000;
queue <int> q;
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
bool inQueue[N];
void SPFA(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(inQueue,0,sizeof(inQueue));
	dis[s] = 0;
	q.push(s);
	while(!q.empty())
	{
		int from = q.front();
		q.pop();
		inQueue[from] = false;
		for(int i = ehead[from];i ;i = e[i].nxt)
		{
			int to = e[i].to;
			if(dis[to] > dis[from] + e[i].val)
			{
				dis[to] = dis[from] + e[i].val;
				if(!inQueue[to])
				{
					q.push(to);
					inQueue[to] = true;
				}
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
	SPFA(s);
	for(int i = 1;i <= n;i++)
		printf("%d ",dis[i] == 0x3f3f3f3f ? 2147483647 : dis[i]);
	return 0;
}