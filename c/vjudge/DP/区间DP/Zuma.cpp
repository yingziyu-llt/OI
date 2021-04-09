#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int f[501][501];
int a[1000];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	memset(f,0x3f,sizeof(f));
	for(int i = 0;i < n;i++)
		f[i][i] = 1;
	for(int len = 2;len <= n;len++)
	{
		for(int i = 0;i + len <= n;i++)
		{
			int j = i + len - 1;
			if(a[i] == a[j])
			{
				if(i + 1 == j) f[i][j] = 1;
				else f[i][j] = f[i + 1][j - 1];
			}
			for(int k = i;k <= j;k++)
				f[i][j] = min(f[i][j],f[i][k] + f[k + 1][j]);
		}
	}
	printf("%d",f[0][n - 1]);
	return 0;
}