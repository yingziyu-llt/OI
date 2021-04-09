#include<stdio.h>
int main()
{
	int a[100],b[100];
	for(int i=0;i<20;i++)
		scanf("%1d",&a[i]);
	for(int i=0;i<20;i++)
		scanf("%1d",&b[i]);
	for(int i=0;i<20;i++)
		printf("%d",a[i]+b[i]);
	return 0;
} 
