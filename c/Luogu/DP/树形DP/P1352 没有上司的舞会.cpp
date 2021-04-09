#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 6100;
int f[N][2],val[N];
bool in[N];

struct Edge
{
	int nxt,to;
}e[N];
int eHead[N],eCnt;
void addEdge(int from,int to)
{
	e[++eCnt].to = to;
	e[eCnt].nxt = eHead[from];
	eHead[from] = eCnt;
}

void dfs(int root)
{
	int son;
	f[root][0] = 0;
	f[root][1] = val[root];
	for(int i = eHead[root];i;i = e[i].nxt)
	{
		son = e[i].to;
		dfs(son);
		f[root][0] += max(f[son][0],f[son][1]);
		f[root][1] = max(f[root][1],f[root][1] + f[son][0]);
	}
	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",&val[i]);
	for(int i = 1;i <= n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x == 0 && y == 0)
			break;
		addEdge(y,x);
		in[x] = true;
	}
	int root;
	for(int i = 1;i <= n + 1;i++)
	{
		if(!in[i])
		{
			root = i;
			break;
		}
	}
	dfs(root);
	printf("%d",max(f[root][0],f[root][1]));
	return 0;
}