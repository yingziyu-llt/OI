#include<stdio.h>
int main()
{
	int a;
	float b,c;
	scanf("%d%f",&a,&b);
	c=(float)a*b/10.0;
	c=(int)(c/10.0+0.5)*10;
	printf("%.0f",c);
	return 0;
}
