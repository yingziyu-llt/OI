#include <stdio.h>
/*bool used[10010];
int a[10010], count, n, m;
int ans[10010];
void nxt(int i)
{
	if (i == n + 1)
	{
		m--; 
		return;
	}
	for (int j = ans[i]; j <= n; j++)
	{
		int t = 0;
		if (!used[j])
		{
			ans[i] = j;
			used[j] = true;
			nxt(i + 1);
			if (m == 0)
				return;
			used[j] = false;
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ans[i]);
	}
	nxt(0);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ans[i]);
	}
	a[0] = 0;
	return 0;
}*/
#include<algorithm>
using namespace std;
int a[100000];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++) scanf("%d",&a[i]);
	for(int i = 0;i < m;i++) next_permutation(a,a + n);
	for(int i = 0;i < n;i++) printf("%d ",a[i]);
}