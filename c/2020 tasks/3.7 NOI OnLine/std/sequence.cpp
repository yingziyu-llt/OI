#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int fa[100010];
int find_fa(int x)
{
	return fa[x] == x ? x : find_fa(x);
}
struct Edge
{
	int nxt,to;
}e[100010];
int ehead[100010],ecnt;
int addedge(int from,int to)
{
	ecnt++;
	e[ecnt] = {ehead[from],to};
	ehead[from] = ecnt;
}
int 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		printf(work() ? "YES\n" : "NO\n");
}