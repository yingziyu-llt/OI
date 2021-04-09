#include<stdio.h>
#include<math.h>
const double PI = 3.14159;
int main()
{
	int h,r;
	scanf("%d %d",&h,&r);
	double V = h * r * r * PI;
	V /= 1000.0;
	double ans = 20.0 / V;
	if(ans != (int)ans) ans = (int)ans + 1;
	printf("%.0lf",ans);
	return 0;
}