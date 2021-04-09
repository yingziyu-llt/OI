#include<stdio.h>
int main()
{
	int a[43]={0};
	int in,sum=0;
	for(int i=0;i<10;i++)
	{
		scanf("%d",&in);
		a[in%42]=1;
	}
	for(int i=0;i<43;i++)
		if(a[i]==1) sum++;
	printf("%d",sum);
	return 0;
}
