#include<stdio.h>
int in;
int main()
{
	int a,b,c,i,n,j,count;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{	a=1;b=2;c=1;
		scanf("%d",&in);
		if(in==1)
		{
			if(i==1) printf("1");
			else printf("\n1");
			continue;
		}
		
		if(in==2)
		{
			if(i==1) printf("2");
			else printf("\n2");
			continue;
		}
		for(j=3;j<=in;j++)
		{
			c=(2*b+a)%32767;
			a=b;
			b=c;
		}
			if(i==1) printf("%d",c);
			else printf("\n%d",c);
	}
	return 0;
}
