#include<stdio.h>
int main()
{
	int a;
	int tmp=0,i,x=0;
	for(i=0;i<12;i++)
	{
		scanf("%d",&a);
		tmp+=300;
		tmp-=a;
		if(tmp<0)
		{
			printf("-%d",i+1);
			return 0;
		}
		x+=tmp/100*100;
		tmp%=100;
	}
	printf("%.0lf",tmp+(double)x*1.2);
	return 0;
} 
