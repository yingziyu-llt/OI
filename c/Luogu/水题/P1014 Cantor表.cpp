#include<stdio.h>
int next(int &x,int &y)
{
	if((x+y)%2==0)
	{
		if(x==1) y+=1;
		else
		{
			x-=1;
			y+=1;
		}
	}
	else
	{
		if(y==1) x+=1;
		else
		{
			x+=1;
			y-=1;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int x=1,y=1;
	for(int i=2;i<=n;i++)
		next(x,y);
	printf("%d/%d",x,y);
	return 0;
}
