#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;
#define N 110000
#define M 1100000
int DFN[N], Low[N];
stack<int> s;
//edge
struct edge
{
	int to, nxt;
} e[M];
int ehead[N], ecnt;
void addEdge(int from, int to)
{
	ecnt++;
	e[ecnt].nxt = ehead[from];
	e[ecnt].to = to;
	ehead[from] = ecnt;
}
//Tarjan
int tmp, co[N], col, si[N];
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
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		addEdge(b, a); //反向连边
	}
	for (int i = 1; i <= n; i++)
		if (!DFN[i])
			tarjan(i);
	for (int i = 1; i <= n; i++)
		for (int j = ehead[i]; j; j = e[j].nxt)
			if (co[i] != co[e[j].to])
				a[co[e[j].to]]++;
	int tot = 0, ans = 0;
	for (int i = 1; i <= col; i++)
		if (!a[i])
			ans = si[i], tot++;
	if (tot == 1)
		printf("%d", ans);
	else
		printf("0");
	return 0;
}