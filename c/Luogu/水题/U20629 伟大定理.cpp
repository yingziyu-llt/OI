#include<stdio.h>
#include<math.h>
int main()
{
	long long a,b,t;
	scanf("%lld%lld%lld",&a,&b,&t);
	printf("%lld",(int)pow((a+b),t));
	return 0;
}
