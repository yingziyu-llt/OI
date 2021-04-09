#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	b+=a*10;
	if(b==0)  {
		printf("0");
		return 0;
	}
	printf("%d",b/19);
	return 0;
} 
