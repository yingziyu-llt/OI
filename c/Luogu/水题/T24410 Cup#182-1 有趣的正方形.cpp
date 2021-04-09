#include<stdio.h>
#include<math.h>
int main()
{
	double x,y;
	scanf("%lf%lf",&x,&y);
	double l=sqrt(x*x+y*y);
	printf("%.2lf %.2lf",4.0*sqrt(2)*l,l*l*2);
	return 0;
}
