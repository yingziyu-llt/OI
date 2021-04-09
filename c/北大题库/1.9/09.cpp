#include<stdio.h>
int a[10001];
int main()
{
	int i,num,fmax=0,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		if(num>fmax)   fmax=num;
		a[num]++;
	}
	for(i=0;i<=fmax;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
} 
