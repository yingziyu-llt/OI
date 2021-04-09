#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std; 
int u[150000],v[150000],w[150000],next[150000],first[150000],n,m,d[150000], tot;
struct a{int u1,v1,w1;}cmp[150000];
int father[150000];

int findfather(int x){return father[x] = father[x] == x ? x : findfather(father[x]);}

void addedge(int st, int end, int val)
{
	u[++tot] = st;
	v[tot] = end;
	w[tot] = val;
	next[tot] = first[st];
	first[st] = tot;
}

inline bool compare(a x,a y){return x.w1 < y.w1;}

int main()
{
	int i;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; i++) first[i] = -1;
	for(i = 1; i <= n; i++) father[i] = i;
	for(i = 1; i <= m; i++)
		scanf("%d%d%d", &cmp[i].u1, &cmp[i].v1, &cmp[i].w1);
	sort(cmp+1,cmp+1+m,compare);
	for(i = 1; i <= m; i++)
	{
		int fa = findfather(cmp[i].u1);
		int fb = findfather(cmp[i].v1);
		if(fa != fb)
		{
			addedge(cmp[i].u1, cmp[i].v1, cmp[i].w1);
			//addedge(cmp[i].v1, cmp[i].u1, cmp[i].w1);
			father[fa] = fb;
		}
	}
	return 0;
}
/*
1 3 10
1 5 30
1 6 100
2 3 5
3 4 50
4 6 10
5 4 20
5 6 60
*/
