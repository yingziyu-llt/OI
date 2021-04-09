#include<stdio.h>
#include<math.h>
int main()
{
	double e;
	e=pow((1+(double)1/2147483647),2147483647);
	printf("%.10lf",e);
	return 0;
}
