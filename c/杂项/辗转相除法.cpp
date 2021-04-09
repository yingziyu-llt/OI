#include<stdio.h>
int main()
{
	int i,j,n,m,r;
	scanf("%d %d",&n,&m);
	r=n%m;
	while(r!=0)
	{
        n=m;
        m=r;
		r=n%m;
	}
	printf("%d",m);
	return 0;
}
