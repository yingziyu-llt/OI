#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MOD = 1e8;
int row[24],can[1 << 13],f[24][1 << 13];
int main()
{
	for(int i = 0;i < 1 << 12;i++)
		can[i] = !(i << 1 & i);
	int m,n;
	while(~scanf("%d%d",&m,&n))
	{
		memset(row,0,sizeof(row));
		memset(f,0,sizeof(f));
		for(int i = 1;i <= m;i++)
			for(int j = 0;j < n;j++)
			{
				int k;
				scanf("%d",&k);
				row[i] = (row[i] << 1) | k;
			}
		for(int i = 0;i < 1 << n;i++)
			if(can[i] && ((row[1] ^ i) | i) == row[1])
				f[1][i] = 1;
		for(int i = 2;i <= m;i++)
			for(int j = 0;j < 1 << n;j++)
			{
				if(!can[j] || ((row[i] ^ j) | j) != row[i])
					continue;
				for(int k = 0;k < 1 << n;k++)
				{
					if(!can[j] || k & j) continue;
					f[i][j] = (f[i][j] + f[i - 1][k]) % MOD;
				}
			}
		int ans = 0;
		for(int i = 0;i < 1 << n;i++)
			ans += f[m][i],ans %= MOD;
		printf("%d\n",ans);
	}
	return 0;
}