#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
int f[1000000];
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n;
	scanf("%d",&n);
	memset(f,0x7f,sizeof(f));
	f[1] = 0;
	f[2] = 1;
	for(int i = 2;i <= n;i++)
	{
		for(int j = 1;j <= n + 1000;j++)
		{
			f[j] = min(f[j],f[i] + abs(i - j));
		}
		int tmp = i;
		while(tmp < n)
		{
			tmp *= i;
			f[tmp] = min(f[tmp],f[i] + 1);
		}
	}
	printf("%d",f[n]);
	return 0;
}