#include<stdio.h>
#include<math.h>
double f(double x)
{
	return pow(x,5)-15*pow(x,4)+ 85*pow(x,3)- 225*pow(x,2)+ 274*x-121;
}
int main()
{
	double l=1.5,r=2.4,mid;
	while(l<r)
	{
		mid=(l+r)/2.0;
		if(fabs(f(mid)-0)<1e-6) break;
		else if(f(mid)>0) l=mid;
		else              r=mid;
	}
	printf("%.7g",mid);
	return 0;
}
