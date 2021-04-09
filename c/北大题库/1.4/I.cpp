#include<stdio.h>
#include<math.h>
int main()
{
	long long int a,b,c;
	scanf("%lld %lld %lld",&a,&b,&c);
	if((a*a+b*b==c*c)||(b*b+c*c==a*a)||(a*a+c*c==b*b)) printf("T");
	else									  printf("F");
	return 0;
}
