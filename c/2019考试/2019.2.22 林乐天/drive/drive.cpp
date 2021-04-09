#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
#define N 11000
#define M 100
int s,k,n,m;

struct edge
{
	int nxt,to,val;
}e[M << 2];
int ehead[N],ecnt;
void addedge(int from,int to,int val)
{
	ecnt++;
	e[ecnt].nxt = ehead[from];
	e[ecnt].to = to;
	e[ecnt].val = val;
	ehead[from] = ecnt;
}

int dis[N],vis[N];
struct node
{
	int val,pos;
	bool operator < (const node &a) const
	{
		return a.val < val;
	}
};
priority_queue<node> q;

void dijkstra()
{
	memset(dis,0x3f,sizeof(dis));
	node now;
	now.val = 0;
	dis[s] = 0;
	now.pos = s;
	q.push(now);
	while(!q.empty())
	{
		node ss = q.top();
		q.pop();
		if(vis[ss.pos] == 1)
			continue;
		vis[ss.pos] = 1;
		for(int i = ehead[ss.pos];i;i = e[i].nxt)
		{
			if(dis[e[i].to] > dis[ss.pos] + e[i].val)
			{
				dis[e[i].to] = dis[ss.pos] + e[i].val;
				now.pos = e[i].to;
				now.val = dis[e[i].to];
				q.push(now);
			}
		}
	}
	return ;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 0;i < m;i++)
	{
		char name[10010];
		int x,y;
		scanf("%d%d%s",&x,&y,name);
		int val = 0;
		for(int i = 1;i < strlen(name);i++)
		{
			val *= 10;
			val += name[i] - '0';
		}
		if(name[0] == 'C')
			addedge(x,y,1000 - val),addedge(y,x,1000 - val);
		else
			addedge(x,y,2000 - val),addedge(y,x,2000 - val);
	}
	scanf("%d%d",&s,&k);
	dijkstra();
	printf("%d",dis[k]);
	return 0;
}