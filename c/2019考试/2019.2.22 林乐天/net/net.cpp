#include<stdio.h>
#include<string.h>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define N 100
#define M 10000
struct edge
{
	int nxt,to;
}e[M],e1[M];
int ehead[N],ecnt;
int n;
void addedge(int from,int to)
{
	ecnt++;
	e[ecnt].nxt = ehead[from];
	e[ecnt].to = to;
	ehead[from] = ecnt;
}
int tmp,DFN[N],col,co[N],si[N],Low[N];
stack <int> s;
void tarjan(int u)
{
	DFN[u] = Low[u] = ++tmp;
	s.push(u);
	for (int i = ehead[u]; i; i = e[i].nxt)
	{
		int v = e[i].to;
		if (!DFN[v])
		{
			tarjan(v);
			Low[u] = min(Low[u], Low[v]);
		}
		else 
			if(!co[v])
				Low[u] = min(Low[u], DFN[v]);
	}
	if (DFN[u] == Low[u])
	{
		co[u] = ++col;
		si[col]++;
		while (s.top() != u)
		{
			si[col]++;
			co[s.top()] = col;
			s.pop();
		}
		s.pop();
	}
}
int a[N];
int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j <= n;j++)
		{
			int to;
			scanf("%d",&to);
			if(to == 0)
				break;
			addedge(i + 1,to);
		}
	}
	for (int i = 1; i <= n; i++)
		if (!DFN[i])
			tarjan(i);
	for (int i = 1; i <= n; i++)
		for (int j = ehead[i]; j; j = e[j].nxt)
			if (co[i] != co[e[j].to])
				a[co[e[j].to]]++;
	int totans1 = 0;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] == 0)
			break;
		else 
			totans1++;
	}
	printf("%d",totans1);
	if(totans1 == 0)
		printf("0");
	else
		printf("1");
	return 0;
}