#include<stdio.h>
#include<math.h>

int a[10000];

int main()
{
	freopen("poly.in","r",stdin);
	freopen("poly.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i = n;i >= 0;i--)
		scanf("%d",&a[i]);
	if(a[n] < 0)
	{
		printf("-");
		if(a[n] != -1)
			printf("%d",-a[n]);
		printf("x^%d",n);
	}
	else if(a[n] > 0)
	{
		if(a[n] != 1)				
		printf("%d",a[n]);
		printf("x^%d",n);
	}
	while(n--)
	{
		if(n == 0)
		{
			if(a[n] == 0)
				break;
			if(a[n] > 0)
				printf("+%d",a[n]);
			if(a[n] < 0)
				printf("%d",a[n]);
			break;
		}
		if(n == 1)
		{
			if(a[n] == 0) continue;
			else if(a[n] < 0)
			{
				printf("-");
				if(a[n] != -1)
					printf("%d",-a[n]);
				printf("x");
			}
			else
			{
				printf("+");
				if(a[n] != 1)
					printf("%d",a[n]);
				printf("x");
			}
			continue;
		}
		if(a[n] == 0) continue;
		else if(a[n] < 0)
		{
			printf("-");
			if(a[n] != -1)
				printf("%d",-a[n]);
			printf("x^%d",n);
		}
		else
		{
			printf("+");
			if(a[n] != 1)
				printf("%d",a[n]);
			printf("x^%d",n);
		}
	}
	return 0;
}
