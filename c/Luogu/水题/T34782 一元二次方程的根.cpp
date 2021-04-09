#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	double dlate=b*b-4*a*c;
	if(dlate==0) 
		printf("x1=x2=%.5lf",(-b+sqrt(b*b-4*a*c))/2*a);
	else if(dlate>0)
		printf("x1=%.5lf;x2=%.5lf",(-b+sqrt(b*b-4*a*c))/2*a,(-b-sqrt(b*b-4*a*c))/2*a);
	else
		printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi",(-b / (2*a)),sqrt(4*a*c-b*b) / (2*a),(-b / (2*a)),sqrt(4*a*c-b*b) / (2*a) );
		return 0;
}
