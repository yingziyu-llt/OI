#include<stdio.h>
#include<algorithm>
#include<queue>
#define INF 2147483647
using namespace std;
typedef pair<int,int>  pii;
int u[150000],v[150000],w[150000],nex[150000],first[150000],n,m,d[150000], tot;
int maxn[21];
bool done[150000];
priority_queue<pii,vector<pii>,greater<pii> >q;
void addedge(int st, int end, int val)
{
	u[++tot] = st;
	v[tot] = end;
	w[tot] = val;
	nex[tot] = first[st];
	first[st] = tot;

}

void dij(int a)
{
  int i;
  for(i = 1; i <= n; i++)d[i] = INF;
  d[a] = 0;
  q.push(make_pair(d[a],a));
  while(!q.empty())
  {
  	int x = q.top().second;q.pop();
  	if(done[x])continue;
  	done[x] = true;
  	for(int e = first[x];e != -1; e = nex[e])
  	 if(d[v[e]] > d[x] + w[e])
  	 {
  	   d[v[e]] = d[x] + w[e];
  	   q.push(make_pair(d[v[e]], v[e]));
  	 }
  }
}
int main()
{
	int i;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; i++)first[i] = -1;
	for(i = 1; i <= m; i++)
	{
		int st,end,val;
		scanf("%d%d%d", &st, &end, &val);
		addedge(st, end, val);
		addedge(end, st, val);
	}
    dij(1);
	printf("%d ", d[3]);
	return 0;
}
