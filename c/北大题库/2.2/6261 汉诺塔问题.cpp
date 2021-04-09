#include<stdio.h>
void movef(int n,char a,char b,char c)//n:盘子数 a:来源柱 b:目标住 c:经过住 
{
	if(n==1) 
	{
		printf("%c->%d->%c\n",a,n,b);
	}
	else 
	{
		movef(n-1,a,c,b);
		printf("%c->%d->%c\n",a,n,b);
		movef(n-1,c,b,a);
	}
}
int main()
{
	int n;
	char a,b,c;
	scanf("%d %c %c %c",&n,&a,&b,&c);
	movef(n,a,b,c);
	return 0;
} 
