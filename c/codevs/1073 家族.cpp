#include <stdio.h>
int father[5010];
int findFather(int a)
{
	return father[a] = father[a] == a ? a : findFather(father[a]);
}
int main()
{
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; i++)
		father[i] = i;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		int fx = findFather(x);
		int fy = findFather(y);
		if (fx != fy)
			father[fx] = fy;
	}
	for (int i = 0; i < p; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (findFather(a) == findFather(a))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
