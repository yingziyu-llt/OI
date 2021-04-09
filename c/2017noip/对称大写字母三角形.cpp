#include <stdio.h>
int main()
{
	int n,i,j;
	char c,temp;
	scanf("%d %c",&n,&c);
	for(i=0;i<n;i++)
	{
		for(j=0;j<(n-(i+1));j++)
		{
			printf(" ");
		}
		for(j=0;j<=i;j++)
		{
			temp=c+j;
			printf("%c",temp);
		}
		for(j=0;j<i;j++)
		{
			temp--;
			printf("%c",temp);
		}
		printf("\n");
	}
	return 0;
}
