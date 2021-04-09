#include<stdio.h>
int main()
{
	int a,n,m=0;
	scanf("%d",&a);
	while(a)
	{
		n=a%10;
		m=m*10+n;
		a=a/10;
	}
	printf("%d",m);
	return 0;
}
