#include<stdio.h>
#define G 0.0000000000667
int main()
{
	long long int M,m,r;
	scanf("%lld %lld %lld",&M,&m,&r);
	printf("%lf",(double)M*(double)m/((double)r*(double)r)*G);
	return 0;
}
