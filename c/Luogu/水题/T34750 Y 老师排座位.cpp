#include<stdio.h>
int change(int a,int b)
{
	for(;;)
	{
		if(a<=b) return a;
		else a-=b;
	}
}
int changelow(int a,int b,int c)
{
	for(;;)
	{
		if(a+b>0) return a+b;
		else a+=c;
	}
}
int main()
{
	int x,y,n,a,b,xc,yc;
	scanf("%d%d%d%d%d%d%d",&x,&y,&n,&a,&b,&xc,&yc);
	for(int i=0;i<n;i++)
	{
		if(x+xc>a) x=change(x+xc,a);
		else if(x+xc<0) x=changelow(x,xc,a); 
		else       x=x+xc;
		if(y+yc>b) y=change(y+yc,b);
		else if(y+yc<0) y=changelow(y,yc,b); 
		else       y=y+yc;
	}
	printf("%d %d",x,y);
	return 0;
}
