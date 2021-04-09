#include<math.h>
#include<stdio.h>
double fx(double x)
{
	x=pow(x,5)-15*pow(x,4)+ 85*pow(x,3)-225*pow(x,2)+ 274*x-121;   //x5 - 15 * x4+ 85 * x3- 225 * x2+ 274 * x - 121
	return x;
}
int main()
{
	double l=1.5,r=2.4,mid;
	while (fabs(l-r)>0.000001)
	{
		mid=(r+l)/2.0;
		if(fx(l)*fx(mid)<0.0)   r=mid;
		else l=mid;
	}
	printf("%.6lf\n",mid);
	return 0;
}
