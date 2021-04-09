#include <stdio.h>
#include <string.h>
char num[100][100],t[100];
double x[100],temp,y[100];
int n,k,ansi;
int main()
{
	int i,j;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%s %lf",&num[i],&x[i]);
	for(i=0;i<n;i++)
		y[i]=x[i];
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(x[i]<x[j])
			{
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
		    }
		}
	}
	for(i=0;i<n;i++)
		if(x[k-1]==y[i]){ansi=i;break;}
	printf("%s %g",num[ansi],y[ansi]);
	return 0;
} 
