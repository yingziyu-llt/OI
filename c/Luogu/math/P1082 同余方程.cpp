#include<stdio.h>
#include<math.h>
void exgcd(int a,int b,int &x,int &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return ;
	}
	exgcd(b,a % b,y,x);
	y -= (a / b) * x;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int x = 0,y = 0;
	exgcd(a,b,x,y);
	printf("%d",(x + b) % b);
	return 0;
}