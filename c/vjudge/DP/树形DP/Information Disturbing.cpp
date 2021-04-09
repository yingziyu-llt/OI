#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

const int INF = 1e6+10;
int mid,f[1100];

struct Edge
{
	int to,nxt,val;
}e[2200];
int ehead[1100],ecnt;
void addedge(int from,int to,int val)
{
	e[++ecnt] = (Edge){to,ehead[from],val};
	ehead[from] = ecnt;
	return ;
}

void dfs(int u,int fa)
{
	bool flag = false;
	f[u] = 0;
	for(int i = ehead[u];i;i = e[i].nxt)
	{
		if(e[i].to == fa)
			continue;
		int v = e[i].to;
		flag = true;
		dfs(v,u);
		if(e[i].val <= mid) f[u] += min(f[v],e[i].val);
		else f[u] += f[v];
	}
	if(!flag) f[u] = INF;
}

int main()
{
	int m,n;
	while(1)
	{
		memset(ehead,0,sizeof(ehead));
		ecnt = 0;
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&m);
		if(n == 0 && m == 0)
			break;
		int l = 0,r = 0;
		for(int i = 1;i < n;i++)
		{
			int a,b,w;
			scanf("%d%d%d",&a,&b,&w);
			addedge(a,b,w);
			addedge(b,a,w);
			r = max(r,w);
		}
		int ans = -1;
		while(l <= r)
		{
			mid = (l + r) >> 1;
			dfs(1,0);
			if(f[1] <= m) r = mid - 1,ans = mid;
			else l = mid + 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}