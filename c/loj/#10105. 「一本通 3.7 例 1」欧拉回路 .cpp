#include<stdio.h>
#include<algorithm>
#include<string.h>
#define N 1100000
using namespace std;
int head[N],tot,ans[N];
struct edge
{
	int to,nxt;
}e[N << 1];
void addedge(int from,int to)
{
	tot++;
	e[tot].to = to;
	e[tot].nxt = head[from];
	head[from] = tot;
}
bool vis[N << 1];
int tot1;
void dfs(int x)
{
	for(int &i = head[x];i;i = e[i].nxt)
	{
		int j = i;
		if(vis[j >> 1])
			continue;
		vis[j >> 1] = true;
		dfs(e[i].to);
		ans[++tot1] = j;
	}
}
int ru[N],chu[N];
int main()
{
	int opt,n,m,cnt;
	int x,y,v;
	scanf("%d%d%d",&opt,&n,&m);
	for(int i = 0;i < m;i++)
	{
		scanf("%d%d",&x,&y);addedge(x,y);
		if(opt == 1)
		{
			addedge(y,x);
			ru[x]++;
			ru[y]++;
		}
		else
		{
			ru[y]++;
			chu[x]++;
			cnt++;
		}
	}
	if(opt == 1)
	{
		for(int i = 1;i <= n;i++)
			if(ru[i] & 1)
			{
				printf("NO");
				return 0;
			}
	}
	else
	{
		for(int i = 1;i <= n;i++)
			if(ru[i] != chu[i])
			{
				printf("NO");
				return 0;
			}
	}
	dfs(1);
	if (tot1 < m)
		return puts("NO") & 0;
	printf("YES\n");
	for(int i = tot1;i > 0;i--)
	{
		printf("%d ",ans[i] & 1 ? (-(ans[i] >> 1)) : (ans[i] >> 1));
	}
	return 0;
}