//非tarjan缩点 TarjanLCA
#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 500000,M = 500000;
struct edge
{
	int to,nxt;
}e[N];
int ehead[N],ecnt;
void addEdge(int from,int to)
{
	e[++ecnt].nxt = ehead[from];
	ehead[from] = ecnt;
	e[ecnt].to = to;
	return ;
}
struct query
{
	int from,to,nxt;
}q[M];
int qhead[M],qcnt;
void addQuery(int from,int to)
{
	q[++qcnt].from = from;
	q[qcnt].to = to;
	q[qcnt].nxt = qhead[from];
	qhead[from] = qcnt;
	return ;
}
int 