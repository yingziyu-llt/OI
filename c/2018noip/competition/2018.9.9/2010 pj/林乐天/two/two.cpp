#include<stdio.h>
int main()
{
	freopen("two.in","r",stdin);
	freopen("two.out","w",stdout);
	int l,r,copy;
	int sum;
	scanf("%d%d",&l,&r);
	for(;l <= r;l++)
	{
		copy = l;
		while(copy > 0)
		{
			if(copy % 10 == 2)
			{
				sum++;
			}
			copy /= 10;
		}
	}
	printf("%d",sum);
	return 0;
} 
