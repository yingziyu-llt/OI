#include<stdio.h>
int main()
{
	char   a;
	int  c,e;
	double d;
	float  b;
	scanf("%c%f%d%lf%d",&a,&b,&c,&d,&e);
	int tmp;
	tmp=b*1e6;
	b=(double)tmp/1e6;
	printf("  %c\n %c%c%c\n%c%c%c%c%c\n%f\n%lf\n%d\n%d",a,a,a,a,a,a,a,a,a,b,(double)c,(int)d,e!=0);
	return 0; 
}
