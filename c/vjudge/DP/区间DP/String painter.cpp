#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int LEN = 110;
int f[LEN][LEN],ans[LEN];
int main()
{
	char a[10010],b[10010];
	while(~scanf("%s%s",a,b))
	{
		int n = strlen(a);
		memset(f,0x3f,sizeof(f));
		for(int i = 0;i < n;i++)
			f[i][i] = 1;
		for(int l = 2;l <= n;l++)
		{
			for(int i = 0;i + l - 1 < n;i++)
			{
				int j = i + l - 1;
				f[i][j] = f[i][j - 1] + 1;
				for(int k = i;k < j;k++)
					if(b[k] == b[j])
						f[i][j] = min(f[i][j],f[i][k] + f[k + 1][j - 1]);
			}
		}
		for(int i = 0;i < n;i++)
		{
			if(a[i] == b[i])
				ans[i] = ans[i - 1];
			else
			{
				ans[i] = f[0][i];
				for(int j = 0;j < i;j++)
					ans[i] = min(ans[i] ,ans[j] + f[j + 1][i]);
			}
		}
		printf("%d\n",ans[n - 1]);
	}
	return 0;
}