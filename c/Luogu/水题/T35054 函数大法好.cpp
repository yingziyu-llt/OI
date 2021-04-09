#include<stdio.h>
#include<math.h>
double f(double x)
{
	return pow(x,5)-3*pow(x,3)+x-1;
} 
int main()
{
	double l=-2,r=0,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(fabs(f(mid)-0)<1e-7) break;
		else if(f(mid)<0) r=mid;
		else              l=mid;
	}
	printf("%lf",mid);
	return 0;
}
