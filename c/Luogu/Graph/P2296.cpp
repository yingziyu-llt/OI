#include<stdio.h>
#include<algorithm>
#include<queue>
const int N = 11000,M = 420000;
using namespace std;
queue <int> q;
pair <int,int> pair1;
queue <pair<int,int> > q1;
struct edge
{
	int nxt,to;
	bool isOpposite;
}e[M];
int color[N];
int head[N],ecnt = 0;
void addEdge(int from,int to,bool isOpposite)
{
	ecnt++;
	e[ecnt].isOpposite = isOpposite;
	e[ecnt].to = to;
	e[ecnt].nxt = head[from];
	head[from] = ecnt;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < m;i++)
	{
		int f,t;
		scanf("%d%d",&f,&t);
		addEdge(f,t,false);
		addEdge(t,f,true);
	}
	int s,t;
	scanf("%d%d",&s,&t);
	q.push(t);
	color[t] = 1;
	while(!q.empty())
	{
		int point = q.front();
		q.pop();
		for(int i = head[point];i;i = e[i].nxt)
		{
			if(color[e[i].to] == 0 && e[i].isOpposite)
			{
				color[e[i].to] = 1;
				q.push(e[i].to);
			}
		}
	}
	for(int i = 1;i <= n;i++)
		if(color[i] == 0)
			for(int j = head[i];j;j = e[j].nxt)
				if(e[j].isOpposite)
					color[e[j].to] = -1;
	q1.push(make_pair(s,0));
	bool success = false;
	while(!q1.empty())
	{
		pair <int,int> point = q1.front();
		q1.pop();
		int pos = point.first;
		int cost = point.second;
		if(pos == t)
		{
			printf("%d",cost);
			success = true;
			break;
		}
		for(int i = head[pos];i;i = e[i].nxt)
		{
			if(color[e[i].to] == 1 && !e[i].isOpposite)
			{
				q1.push(make_pair(e[i].to,cost + 1));
				color[e[i].to] = 0;
			}
		}
	}
	if(!success)
		printf("-1");
	return 0;
}