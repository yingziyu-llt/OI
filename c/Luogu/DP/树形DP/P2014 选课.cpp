#include<algorithm>
#include<stdio.h>
const int N = 400;
int f[N][N],val[N];
int m,n;
using namespace std;

struct Edge
{
	int to,nxt;
}e[N];
int eHead[N],eCnt;
void addEdge(int from,int to)
{
	e[++eCnt].to = to;
	e[eCnt].nxt = eHead[from];
	eHead[from] = eCnt;
}

int dfs(int now)
{
	int son = 1,nson;
	f[now][1] = val[now];
	for(int u = eHead[now];u;u = e[u].next)
	{
		nson = dfs(e[u].to);
		for(int i = son;i >= 1;i--)
		{
			for(int j = 1;j <= nson;j++)
			{
				f[now][i + j] = max(f[now][i + j],f[now][i] + f[e[u].to][j]);
			}
		}
		son += nson;
	}
	return son;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 2;i <= n + 1;i++)
	{
		int v;
		scanf("%d%d",&v,&val[i]);
		v++;//坐标平移
		addEdge(v,i);
	}
	dfs(1);
	printf("%d",f[1][m + 1]);
	return 0;
}