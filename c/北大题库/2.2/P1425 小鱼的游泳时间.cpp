#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	b+=a*60;
	d+=c*60;
	int tmp;
	tmp=d-b;
	e=tmp/60;
	f=tmp%60;
	printf("%d %d",e,f);
	return 0;
} 
