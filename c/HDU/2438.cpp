#include <math.h>
#include <stdio.h>
double H,l,d,Y;
double f(double theta)
{
	return (H - l * sin(theta) - d / cos(theta)) / tan(theta);
}
int main()
{
	while(~scanf("%lf%lf%lf%lf",&H,&Y,&l,&w))
	{
		double l = 0.001,r = 1.58; 
		while(r - l > 0.00001)
		{
			double nl = l + (r - l) / 3.0,nr = r - (r - l) / 3.0;
			if(f(nl) < f(nr))
				l = nl;
			else
				r = nr;
		}
		if()
	}
}