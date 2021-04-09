#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double calc()
{
	char a[100];
	scanf("%s",a);
	if(a[0]=='+')  return calc()+calc();
	if(a[0]=='-')  return calc()-calc();
	if(a[0]=='*')  return calc()*calc();
	if(a[0]=='/')  return calc()/calc();
	return atof(a);
}
int main()
{
	printf("%f\n",calc());
	return 0;
}
