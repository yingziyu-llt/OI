#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
bool vis[110000];
int a[110000],b[110000];
int op[110000][3];
int main()
{
	int T;
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		memset(vis,0,sizeof(vis));
		long long asum = 0,bsum = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			asum += a[i];
		}
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&b[i]);
			bsum += b[i];
		}
		bool flag2 = true; 
		for(int i = 1;i <= m;i++)
		{
			scanf("%d%d%d",&op[i][0],&op[i][1],&op[i][2]);
			if(op[i][0] != 2) flag2 = false;
			if(op[i][0] == 2 && op[i][1] == op[i][2]) i--,m--;
			else vis[op[i][1]] = vis[op[i][2]] = true;
		}
		bool flag = true;
		if(asum % 2 != bsum % 2)
		{
			printf("NO\n");
			continue;
		}
		if(flag2 && asum != bsum)
		{
			printf("NO\n");
			continue;
		}
		for(int i = 1;i <= n;i++)
			if(!vis[i])
				if(a[i] != b[i])
				{
					flag = false;
					printf("NO\n");
					break;
				}
		if(!flag) continue;
		printf("YES\n");
	}
	return 0;
}