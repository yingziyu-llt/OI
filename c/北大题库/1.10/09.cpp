#include<stdio.h>
int a[1001],x,y=0;
int main()
{
	int i,n,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(a[x]==0) y++;  
		a[x]++;
	}
	printf("%d\n",y);
	for(i=0;i<1000;i++)
	{
		if(a[i]>=1)  printf("%d ",i);
	}
	return 0;
}
