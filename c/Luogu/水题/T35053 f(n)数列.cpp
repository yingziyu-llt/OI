#include<stdio.h>
int b[10000000]={0,1,2};
long long func(int a)
{
	if(a==1)
	return 1;
	else if(a==2)
	return 2;
	else
	{
		if(b[a-1]==0) b[a-1]=func(a-1);
		if(b[a-2]==0) b[a-2]=func(a-2);
		b[a]=3*b[a-1]+2*b[a-2];
		return b[a];
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld",func(n));
	return 0;
}
