#include<stdio.h>
int main()
{
	int a,n;
	scanf("%d",&a);
	while(a)
	{
		n=a%10;
		printf("%d ",n);
		a=a/10;
	}
	return 0;
}
