#include<stdio.h>
#include<algorithm>
using namespace std;
int f[40][40];
int root[40][40];
void print(int l,int r)
{
	if(l > r)
		return ;
	printf("%d ",root[l][r]);
	print(l,root[l][r] - 1);
	print(root[l][r] + 1,r);
	return ;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&f[i][i]);
		f[i][i - 1] = 1;
		root[i][i] = i;
	}
	for(int len = 1;len <= n;len++)
	{
		for(int i = 1;i + len <= n;i++)
		{
			for(int j = i;j <= i + len;j++)
			{
				if(f[i][i + len] < (f[i][j - 1] * f[j + 1][i + len] + f[j][j]))
				{
					f[i][i + len] = f[i][j - 1] * f[j + 1][i + len] + f[j][j];
					root[i][i + len] = j;
				}
			}
		}
	}
	printf("%d\n",f[1][n]);
	print(1,n);
	return 0;
}