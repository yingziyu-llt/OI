#include<stdio.h>
#include<math.h>
#include<algorithm>
double a,b,c,d;
double makeSidePoint1()
{
	return ((-2*b)-sqrt(4*b*b-12*a*c))/(6*a);
}
double makeSidePoint2()
{
	return ((-2*b)+sqrt(4*b*b-12*a*c))/(6*a);
}
double f(double x)
{
	return x * x * x * a + x * x * b + x * c + d;
} 
double search1f(double l,double r)//单增区间  
{
	double mid;
	while(fabs(r - l) > 0.0001)
	{
		mid = (l + r) / 2.0;
		if(f(mid) < 0) 
			l = mid;
		else if(f(mid) > 0)
			r = mid;
		else
			return mid;
	}
	return mid;
}
double search2f(double l,double r)//单减区间 
{
	double mid;
	while(fabs(r - l) > 0.0001)
	{
		mid = (l + r) / 2.0;
		if(f(mid) < 0) 
			r = mid;
		else if(f(mid) > 0)
			l = mid;
		else
			return mid;
	}
	return mid;
}
int main()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	double ans[3];
	double point1 = makeSidePoint1();
	double point2 = makeSidePoint2();
	if(f(-100) - f(point1) < 0)
	{
		ans[0] = search1f(-100,point1); 
		ans[1] = search2f(point1,point2);
		ans[2] = search1f(point2,100);
	}
	else
	{
		ans[0] = search2f(-100,point1); 
		ans[1] = search1f(point1,point2);
		ans[2] = search2f(point2,100);
	}
	std::sort(ans,ans+3);
	printf("%.2lf %.2lf %.2lf",ans[0],ans[1],ans[2]);
}
