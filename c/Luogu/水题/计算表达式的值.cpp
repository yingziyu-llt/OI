#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,d,e,x,ans;
	scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&x);
	ans=a*sin(x)+b*cos(x)+c*pow(x,4)+d*pow(x,3)+pow(x,e);
	printf("%lf",ans);
	return 0;
}
