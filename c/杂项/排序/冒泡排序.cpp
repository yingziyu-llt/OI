#include<stdio.h>
int main()
{
	int a[100]={0},i,j,x,temp;
	
	
	
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		scanf("%d",&a[i]);
	}
	
	
	for(i=0;i<x;i++)
	{
		for(j=i+1;j<x;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	
	for(i=0;i<x;i++)
	{
		printf("%d ",a[i]); 
	}
	return 0;
} 
