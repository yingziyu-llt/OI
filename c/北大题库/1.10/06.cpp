#include<stdio.h>
int in[20],x[101];
int main()
{
	int i,j,k,z;
	for(i=0;i<10;i++)	scanf("%d",&in[i]);
	for(i=0;i<10;i++)
	{
		x[in[i]]++;
	}
	for(i=100;i>0;i--)	
		if(i%2==1)
			for(;x[i]!=0;x[i]--)
				printf("%d ",i);
	for(i=0;i<=100;i++)	
		if(i%2==0)
			for(;x[i]!=0;x[i]--)
				printf("%d ",i);
}
