#include<stdio.h>
int a;
int main()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&a);
			printf("%d ",(bool)a);
		} 
		printf("\n");
	}
	return 0;
}
