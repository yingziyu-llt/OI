#include<stdio.h>
#include<math.h>
int main()
{
	double S,r;
	scanf("%lf",&S);
	r=sqrt(S/3.14);
	if(fabs(r-(int)r)<=1e-7&&r>0) printf("YES");
	else                     printf("NO");
	return 0;
}
