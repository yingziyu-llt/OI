#include<stdio.h>
int main()
{
	int a,b,c,d;
	scanf("%d %d",&a,&b);
	c=a%b;
	d=a/b;
	if(c==0) c=0;
	else    d++;
	printf("%d",d);
	return 0;
}	
