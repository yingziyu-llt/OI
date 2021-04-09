#include<stdio.h>
int main()
{
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	if(a==c&&b==c)	printf("a,b,c=?Deng Bian San Jiao Xing");
	else if(a==b||b==c||c==a) printf("a,b,c=?Deng Yao San Jiao Xing");
	else					  printf("a,b,c=?Yi Ban San Jiao Xing");
	return 0;
} 
