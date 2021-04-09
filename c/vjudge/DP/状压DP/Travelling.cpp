#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int n,m,e[11][11],f[11][60000],stat[60000][11],mi[12];

int main()
{
	mi[1] = 1;
	for(int i = 2;i <= 11;i++) mi[i] = mi[i - 1] * 3;
	for(int i = 0;i <= 59050;i++)
	{
		int t = i;
		for(int j = 1;j <= 10;j++)
		{
			stat[i][j] = t % 3;
			t /= 3;
		}
	}
	while(~scanf("%d%d",&n,&m))
	{
		int ans = 0x3f3f3f3f;
		memset(e,0x3f,sizeof(e));
		memset(f,0x3f,sizeof(f));
		while(m--)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			e[x][y] = e[y][x] = min(z,e[x][y]);
		}
		for(int i = 0;i <= n;i++)
			f[i][mi[i]] = 0;
		for(int i = 0;i < mi[n + 1];i++)
		{
			bool flag = true;
			for(int j = 1;j <= n;j++)
			{
				if(!stat[i][j])
				{
					flag = false;
					continue;
				}
				for(int k = 1;k <= n;k++)
				{
					int l = i - mi[j];
					if(!stat[i][k]) continue;
					f[j][i] = min(f[j][i],f[k][l] + e[k][j]);
				}
			}
			if(flag)
				for(int j = 1;j <= n;j++)
					ans = min(ans,f[j][i]);
		}
		if(ans == 0x3f3f3f3f) printf("-1\n");
		else printf("%d\n",ans); 
	}
	return 0;
}