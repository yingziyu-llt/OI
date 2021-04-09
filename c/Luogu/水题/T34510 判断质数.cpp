#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d",&a);
	for(int i=2;i<a;i++)
	{
		if(a%i==0) 
		{
			printf("0");
			return 0;
		}
	}
	printf("1");
	return 0;
} 
