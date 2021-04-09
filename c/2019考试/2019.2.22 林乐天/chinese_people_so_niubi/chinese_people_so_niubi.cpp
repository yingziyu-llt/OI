#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 110000
#define M 110000
int n,m;
struct edge
{
	int nxt,to,val;
}e[M << 1];
int ehead[N],ecnt;
void addedge(int from,int to,int val)
{
	ecnt++;
	e[ecnt].nxt = ehead[from];
	e[ecnt].to = to;
	e[ecnt].val = val;
	ehead[from] = ecnt;
}
int ans;
void dfs(int now,int la,int val)
{
	if(val < 10)
		ans++,val = 100;
	for(int i = ehead[now];i;i = e[i].nxt)
	{
		if(e[i].to == la)
			continue;
		dfs(e[i].to,now,val / e[i].val);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n - 1;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		addedge(x,y,w);
		addedge(y,x,w);
	}
	dfs(1,0,100);
	printf("%d",ans + 1);
	return 0;
}