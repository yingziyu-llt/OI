#include<stdio.h>
int main()
{
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	if(x > y)
	{
		if(x <= y + z)
			printf("?");
		else
			printf("+");
	}
	else if(x == y)
	{
		if(z == 0) printf("0");
		else printf("?");
	}
	else
	{
		if(y <= x + z)
			printf("?");
		else
			printf("-");
	}
	return 0;
}