#include<stdio.h>
int mem[1000];
int pd(int a)
{
	if(mem[a]!=0) return mem[a];
	int sum=1;
	for(int i=1;i<=a/2;i++)
	{
		sum+=pd(i);
	}
	mem[a]=sum;
	return mem[a];
}
int main()
{
	int a;
	scanf("%d",&a);
	printf("%d",pd(a));
	return 0;
}
