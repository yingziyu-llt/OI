#include<stdio.h>
int w[10110],a[10000];
int m,n;
int tot,sum;
bool pd()
{
	for(int i = 0;i < m;i++)
		if(a[i] != 0)
			return false;
	return true;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++)
		scanf("%d",&w[i]);
	for(int i = 0;i < m;i++)
		a[i] = w[i];
	int x = m;
	while(true)
	{
		int min = 200,mini;
		for(int i = 0;i < m;i++)
			if(a[i] < min && a[i] != 0)
				min = a[i];
		for(int i = 0;i < m;i++)
		{
			if(a[i] > 0)
				a[i] -= min;
			if(a[i] == 0)
				a[i] = w[x++];
		}
		tot += min;
		if(pd()) break;
	}
	printf("%d",tot);
	tot = 0;
	return 0;
}
