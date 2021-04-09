#include<stdio.h>
void cut(int a,int &count)
{
	count++;
	while(a>70)
	{
		a-=70;
		count++;
	}
	return;
}
int input(int a[])
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	return n;
}
void output(float a)
{
	printf("%.1f",a);
	return;
}
int main()
{
	int a[1000],n,i,count=0;
	n=input(a);
	for(i=0;i<n;i++)
	{
		cut(a[i],count);
	}
	output((float)count*0.1);
	return 0;
}
