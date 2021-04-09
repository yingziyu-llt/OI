#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int maxn;
	scanf("%d",&maxn);
	int ans = maxn;
	for(int i = 1;i < n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		int k = maxn - tmp;
		if(k > 0)
		{
			ans += k;
		}
		maxn = tmp;
	}
	printf("%d",ans);
	return 0;
}