#include<stdio.h>
int a[12];
int main()
{
	int x,i,count=0;
	for(i=0;i<10;i++)   scanf("%d",&a[i]);
	scanf("%d",&x);
	for(i=0;i<10;i++)   if(a[i]<=30+x) count++;
	printf("%d",count);
}
