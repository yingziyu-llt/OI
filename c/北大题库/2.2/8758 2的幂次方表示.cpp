#include<stdio.h>
int pd(int a)
{
	int i,sum=1;
	for(i=1;1;i++)
	{
		sum*=2;
		if(sum>a) 
		break;
	}
	i--;
	sum/=2;
	if(i==0) printf("2(0)");
	else if(i==1) printf("2");
	else if(i==2) printf("2(2)");
	else
	{
		printf("2(");
		pd(i);
		printf(")");
	}
	if(a-sum==0) return 0;
	else 
	{
		printf("+");
		pd(a-sum);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	pd(n);
	return 0;
}
