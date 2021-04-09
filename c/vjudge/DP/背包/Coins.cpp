#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[110],c[110],f[100000];
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		if(n == 0 && m == 0)
			break;
		memset(f,0,sizeof(f));
		for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
		for(int i = 1;i <= n;i++) scanf("%d",&c[i]);
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= c[i];c[i] -= j,j <<= 1)
				for(int k = m;k >= a[i] * j;k--)
					f[k] = max(f[k],f[k - a[i] * j] + a[i] * j);
			for(int k = m;k >= a[i] * c[i];k--)
				f[k] = max(f[k],f[k - a[i] * c[i]] + a[i] * c[i]);
		}
		int ans = 0;
		for(int i = 1;i <= m;i++)
			if(f[i] == i)
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}