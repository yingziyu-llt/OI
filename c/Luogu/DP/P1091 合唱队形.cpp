#include <stdio.h>
#include<algorithm>
using namespace std;
int	up[110];
int down[110];
int a[100];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	for(int i = 0;i < n;i++)
	{
		up[i] = 1;
		for(int j = 0 ;j < i;j++)
		{
			if(a[i] > a[j])
			{
				up[i] = max(up[i],up[j] + 1);
			}
		}
	}
	for(int i = n - 1;i >= 0;i--)
	{
		down[i] = 1;
		for(int j = n - 1;j >= i;j--)
		{
			if(a[i] > a[j])
			{
				down[i] = max(down[i],down[j] + 1);
			}
		}
	}
	int maxn = 0;
	for(int i = 0;i < n;i++)
		maxn = max(down[i] + up[i] - 1,maxn);
	printf("%d",n - maxn);
	return 0;
} 