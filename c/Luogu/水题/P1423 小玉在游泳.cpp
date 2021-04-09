#include<stdio.h>
int main()
{
	int i;
	double x,y,tmp=0;
	scanf("%lf",&x);
	y=2;
	for(i=0;tmp<x;i++)
	{
		tmp+=y;
		y*=0.98;
	}
	printf("%d",i);
	
}
