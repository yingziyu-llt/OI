#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int f[3100][3100],money[3100];

struct edge
{
	int to,nxt,val;
}e[3100];
int ehead[3100],ecnt;
void addedge(int from,int to,int val)
{
	ecnt++;
	e[ecnt] = {to,ehead[from],val};
	ehead[from] = ecnt;
}

int n,m;

int dfs(int root,int fa)
{
	int cnt = 0;
	bool flag = false;
	for(int i = ehead[root];i;i = e[i].nxt)
	{
		flag = true;
		int cntx = cnt;
		cnt += dfs(e[i].to,root);
		for(int j = cnt;j >= 0;j--)
			for(int k = 0;k <= cnt - cntx;k++)
				f[root][j] = max(f[root][j],f[root][j - k] + f[e[i].to][k] - e[i].val);
	}
	if(!flag)
		return 1;
	return cnt;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n - m;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j = 0;j < k;j++)
		{
			int to,c;
			scanf("%d%d",&to,&c);
			addedge(i,to,c);
		}
	}
	for(int i = 1;i <= n;i++) 
		for(int j = 0;j <= n;j++)
			f[i][j] = -1e9;
	for(int i = 1;i <= n;i++)
		f[i][0] = 0;
	for(int i = n - m + 1;i <= n;i++)
		scanf("%d",&f[i][1]);
	dfs(1,0);
	for(int i = m;i >= 0;i--)
		if(f[1][i] >= 0)
		{
			printf("%d",i);
			break;
		}
	return 0;
}