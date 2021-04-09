#include<stdio.h>
#include<string.h>
#include<algorithm>
const int N = 11000;
using namespace std;
struct edge
{
	int to,val,nxt;
}e[N << 1];
int head[N],edgeCnt = 0;
int rootx;
void addedge(int from,int to,int val)
{
	e[++edgeCnt].nxt = head[from];
	e[edgeCnt].val = val;
	e[edgeCnt].to = to;
	head[from] = edgeCnt;
}
int d[N],tot,dis[N],vis[N],sumch[N],f[N],sum;
int getdis(int root,int father)
{
	dis[++tot] = d[root];
	for(int i = head[root];i ;i = e[i].nxt)
	{
		int to = e[i].to;
		if(to == father || vis[to]) continue;
		d[to] = d[root] + e[i].val;
		getdis(to,root);
	}
	return ;
}
int getroot(int root,int father)
{
	sumch[root] = 1;
	f[root] = 0;
	for(int i = head[root];i;i = e[i].to)
	{
		int to = e[i].to;
		if(to == father || vis[to])
			continue;
		getroot(to,root);
		sumch[root] += sumch[to];
		f[root] = max(f[root],sumch[to]);
	}
	f[root] = max(sum - sumch[root],f[root]);
	if(f[root] < f[rootx]) rootx = root;
	return ; 
}
int main()
{

}