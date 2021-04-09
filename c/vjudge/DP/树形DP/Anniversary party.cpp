#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int happy[10010],f[10010][2];
int sum[10010];
struct edge
{
	int to,nxt;
}e[20010];
int ehead[10010],ecnt;
void addedge(int f,int t)
{
	ecnt++;
	e[ecnt].to = t;
	e[ecnt].nxt = ehead[f];
	ehead[f] = ecnt;
}

void dfs(int n)
{
	f[n][0] = 0,f[n][1] = happy[n];
	for(int i = ehead[n];i;i = e[i].nxt)
	{
		dfs(e[i].to);
		f[n][0] += max(f[e[i].to][0],f[e[i].to][1]);
		f[n][1] += f[e[i].to][0];
	}
	return ;
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(ehead,0,sizeof(ehead));
		ecnt = 0;
		memset(f,0,sizeof(f));
		memset(sum,0,sizeof(sum));
		if(n == 0) break;
		for(int i = 1;i <= n;i++)
			scanf("%d",&happy[i]);
		for(int i = 1;i < n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			addedge(y,x);
			sum[x]++;
		}
		scanf("%*d%*d");
		for(int i = 1;i <= n;i++)
		{
			if(sum[i] == 0)
			{
				dfs(i);
				printf("%d\n",max(f[i][0],f[i][1]));
				break;
			}
		}
	}
}