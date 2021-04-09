#include<queue>
#include<stdio.h>
#include<string.h>
using namespace std;

#define N 11000
#define M 510000
int m,n,s;
queue <int> q;
/***************************/
struct edge
{
	int to,nxt,val;
}e[M];
int ehead[N],ecnt;
void addedge(int u,int v,int w)
{
	ecnt++;
	e[ecnt].to = v;
	e[ecnt].val = w;
	e[ecnt].nxt = ehead[u];
	ehead[u] = ecnt;
}
/***************************/
bool vis[N];
int dis[N];
void SPFA()
{
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	vis[s] = true;
	q.push(s);
	while(!q.empty())
	{
		int top = q.front();
		q.pop();
		vis[top] = 0;
		for(int i = ehead[top];i != 0;i = e[i].nxt)
		{
			if(dis[e[i].to] > dis[top] + e[i].val)
			{
				if(vis[e[i].to] == 0)
       			{
        			vis[e[i].to] = 1;
        			q.push(e[i].to);
    			}
				dis[e[i].to] = dis[top] + e[i].val;
			}
		}
	}
}
/***************************************/
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i = 1;i <= m;i++)
	{
		int u,v,val;
		scanf("%d%d%d",&u,&v,&val);
		addedge(u,v,val);
	}
	SPFA();
	for(int i = 1;i <= n;i++)
	{
		if(dis[i] == 0x3f3f3f3f)
			printf("2147483647 ");
		else
			printf("%d ",dis[i]);
	}
	return 0;
}