#include<stdio.h>
#include<math.h>
int main()
{
	double h,l,v1,v2,x;
	scanf("%lf%lf%lf",&l,&h,&v1);
	x = sqrt(l * l - h * h);
	v2 = sqrt(l * l -(h - v1) * (h - v1)) - x;
	printf("%.2lf",v2);
	return 0;
}