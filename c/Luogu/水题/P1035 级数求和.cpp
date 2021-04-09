#include<stdio.h>
int main()
{
	int k,i;
	double x=0;
	scanf("%d",&k);
	i=0;
	while(x<k)
	{
		i++;
		x=x+1.0/i;
	}
		
 	printf("%d",i);
 	return 0;
}
