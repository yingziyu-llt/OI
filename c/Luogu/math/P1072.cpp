#include <stdio.h>
int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b,a % b);
}
int main()
{
	int a0,a1,b0,b1,ans = 0,n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		ans = 0;
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
		for(int y = 1;y * y <= b0;y++)
		{
			if(b0 % y == 0)
			{
				int x = b1 / b0 * y;
				if(x == b1 / b0 * gcd(x,b0) && a1 == gcd(x,a0))
					ans++;
				x = b1 / b0 * (b0 / y);
				if(x == b1 / b0 * gcd(x,b0) && a1 == gcd(x,a0) && (b0 / y) != y)
					ans++;
			}
		}
		printf("%d\n",ans);
	}
}
