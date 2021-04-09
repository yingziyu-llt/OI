#include<stdio.h>
#include<math.h>
int main()
{
	double v,th;
	scanf("%lf %lf",&v,&th);
	double vx,vy,t,x,y;
	vx=v*sin(th);
	vy=v*cos(th);
	t=vy/10.0;
	x=vx*t;
	y=vy*t/2.0;
	printf("%lf %lf",x,y);
	return 0;
}
