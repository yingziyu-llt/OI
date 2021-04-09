#include<stdio.h>
unsigned int a;
int main()
{
	scanf("%u",&a);
	printf("%u",(a>>16)+(a<<16));
	return 0;
}
