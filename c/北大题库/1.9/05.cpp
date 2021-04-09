#include <stdio.h>
int a[10000],m;
int main()
{
	int i,max=-10001,min=10001;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		if(max<a[i])   max=a[i];
		if(min>a[i])   min=a[i];
	} 
	printf("%d",max-min);
	return 0;
} 
