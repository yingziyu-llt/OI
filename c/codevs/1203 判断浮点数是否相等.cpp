#include<stdio.h>
#include<math.h>
bool isSame(double a,double b)
{
	return fabs(a-b)<=1e-8;
}
int main()
{
	double a,b;
	scanf("%lf%lf",&a,&b);
	if(isSame(a,b))  printf("yes");
	else             printf("no");
	return 0;
}
