#include <stdio.h>
int main()
{
	int y;
	double r,m;
	scanf("%lf%lf%d",&r,&m,&y);
	r=1+r/100.0;
	for(int i=1;i<=y;i++)
	{
		m=m*r;
	}
	y=m;
	printf("%d",y);
}

