#include<stdio.h>
int main()
{
	int n,a[1000],max,min;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	max=min=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]<min)  min=a[i];
		if(a[i]>max)  max=a[i];
	}
	printf("%d %d",min,max);
	return 0;
}
