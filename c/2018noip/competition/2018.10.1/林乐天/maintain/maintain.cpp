#include <algorithm>
#include <stdio.h>
using namespace std;
struct node
{
	int st, ed, val;
} n[100000];
int m,nn;
int fa[10000];

int findfather(int x)
{
	if (fa[x] == x)
		return x;
	return fa[x] = findfather(fa[x]);
}

bool cmp(node a,node b)
{
	return a.val < b.val;
}
int ku(int mm)
{
	int ans = 0;
	int tot = 0;
	for (int i = 0; i <= mm; i++)
	{
		int u = findfather(n[i].st);
		int k = findfather(n[i].ed);
		if (u != k)
		{
			ans += n[i].val;
			tot++;
			fa[u] = k;
		}
		if(tot == nn - 1) return ans;
	}
	return -1;
}
int main()
{
	freopen("maintain.in","r",stdin);
	freopen("maintain.out","w",stdout);
	scanf("%d%d",&nn,&m);
	for(int i = 0;i < m;i++)
	{
		scanf("%d%d%d",&n[i].st,&n[i].ed,&n[i].val);
		n[i].ed--;
		n[i].st--;
		for(int j = 0;j < nn;j++)
			fa[j] = j;
		sort(n,n + i + 1,cmp);
		int ans = ku(i);
		printf("%d\n",ans);
	}

	return 0;
}
