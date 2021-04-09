#include<stdio.h>
int queue[10010];
int main()
{
	int n;
	scanf("%d",&n);
	int tot = 0;
	for(int i = 1;i <= n;i++)
	{
		tot = (tot + i) % n;
		queue[tot] = i;
	}
	for(int i = 1;i <= n;i++)
		printf("%d ",queue[i]);
	return 0;
}