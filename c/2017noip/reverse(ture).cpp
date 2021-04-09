#include<stdio.h>
int main()
{
	int a,b;
	bool y;
	scanf("%d",&a);
	b=(a>0);
	if(y)
		a=a;
	else
		a=-a;
	b=0;
	do
	{
		b=b*10+a%10;
		a=a/10;
	}
	while(a!=0);
	
	if(!y)
		b=-b;
		
	printf("%d",b);
}
