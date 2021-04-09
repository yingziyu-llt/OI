#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int ax[10010],a[10010];
int main()
{
	int cnt = 0;
	while(1)
	{
		cnt++;
		int n,q;
		scanf("%d%d",&n,&q);
		memset(ax,0,sizeof(ax));
		if(n == 0 && q == 0)
			break;
		for(int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		sort(a + 1,a + n + 1);
		for(int i = 1;i <= n;i++)
		{
			int x = a[i];
			if(ax[x] == 0)
				ax[x] = i;
		}
		printf("CASE# %d:\n",cnt);
		for(int i = 0;i < q;i++)
		{
			int s;
			scanf("%d",&s);
			if(ax[s])
				printf("%d found at %d\n",s,ax[s]);
			else
				printf("%d not found\n",s);
		}
	}
	return 0;
}
/*4 1
2
3
5
1
5
5 2
1
3
3
3
1
2
3
0 0*/