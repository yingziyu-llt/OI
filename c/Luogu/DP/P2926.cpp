#include<stdio.h>
int max(int a,int b){return a > b?a : b;}
const int N = 110000;
int b[N],a[N];
int ans[N];
int main()
{
	int n;
	int maxn = -100;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
		maxn = max(maxn,a[i]);
	}
	for(int i = 1;i <= maxn;i++)
	{
		if(b[i])
		{
			for(int j = 1;j * i <= maxn;j++)
			{
				ans[i * j] += b[i];
			}
		}
	}
	for(int i = 1;i <= n;i++)
		printf("%d\n",ans[a[i]] - 1);
	return 0;
}