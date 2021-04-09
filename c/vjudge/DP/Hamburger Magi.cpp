#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int e[20],v[20],need[30][30],f[1 << 16][101];
bool check(int x,int a)
{
	for(int i = 1;i <= need[a][0];i++)
		if(((1 << need[a][i]) & x) == 0)
			return false;
	return true;

}
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int n,t;
		scanf("%d%d",&n,&t);
		for(int i = 0;i < n;i++)
			scanf("%d",&v[i]);
		for(int i = 0;i < n;i++)
			scanf("%d",&e[i]);
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&need[i][0]);
			for(int j = 1;j <= need[i][0];j++)
				scanf("%d",&need[i][j]),need[i][j]--;
		}
		memset(f,-1,sizeof(f));
		f[0][t] = 0;int ans = 0;
		for(int i = 0;i < (1 << n);i++)
		{
			for(int j = 0;j < n;j++)
			{
				if(i & (1 << j) || !check(i,j))
					continue;
				for(int k = 0;k <= t - e[j];k++)
					if(f[i][k + e[j]] != -1)
						f[i | (1 << j)][k] = max(f[i | (1 << j)][k],f[i][k + e[j]] + v[j]);
			}
			for(int j = 0;j <= t;j++)
				ans = max(f[i][j],ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}