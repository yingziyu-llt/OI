#include<stdio.h>
#include<algorithm>

using namespace std;

const int N = 501000;

//IO start
int input()
{
	char c = getchar();
	while(c < '0' || c > '9')
		c = getchar();
	int a = 0;
	while(c >= '0' && c <= '9')
	{
		a = (a << 1) + (a << 3) + c - '0';
		c = getchar();
	}
	return a;
}
//IO end

//edge start
struct Edge
{
	int from,to,nxt;
}e[N << 1];
int edgeCount = 0,edgeHead[N];
void addEdge(int from,int to)
{
	edgeCount++;
	e[edgeCount].from = from;
	e[edgeCount].to = to;
	e[edgeCount].nxt = edgeHead[from];
	edgeHead[from] = edgeCount;
}
//edge end

//树剖 start
int son[N],fa[N],dep[N],mson[N];
void getSon(int now,int father,int depth)
{
	son[now] = 1;
	dep[now] = depth;
	fa[now] = father;
	for(int i = edgeHead[now];i;i = e[i].nxt)
	{
		if(e[i].to == father)
			continue;
		getSon(e[i].to,now,depth + 1);
		son[now] += son[e[i].to];
		if(son[mson[now]] < son[e[i].to])
			mson[now] = e[i].to;
	}
}

int top[N],id[N],idcnt;
void getLine(int now,int fa)
{
	id[now] = ++idcnt;
	if(top[now] == 0)
		top[now] = now;
	if(mson[now] == 0)
		return ;
	top[mson[now]] = top[now];
	getLine(mson[now],now);
	for(int i = edgeHead[now];i;i = e[i].nxt)
	{
		if(e[i].to == fa || e[i].to == mson[now])
			continue;
		getLine(e[i].to,now);
	}
}
//树剖 end

//lca start
int LCA(int from,int to)
{
	while(top[from] != top[to])
	{
		if(dep[top[from]] < dep[top[to]])
		{
			int tmp = from;
			from = to;
			to = tmp;
		}
		from = fa[top[from]];
	}
	return dep[from] < dep[to] ? from : to;
}
//lca end

int main()
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i = 1;i < n;i++)
	{
		int x,y;
		x = input();
		y = input();
		addEdge(x,y);
		addEdge(y,x);
	}
	getSon(s,0,1);
	getLine(s,0);
	for(int i = 0; i < m;i++)
	{
		int x,y;
		x = input();
		y = input();
		int lca = LCA(x,y);
		printf("%d\n",lca);
	}
	return 0;
}