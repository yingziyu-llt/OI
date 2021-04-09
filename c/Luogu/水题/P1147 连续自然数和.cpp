#include<stdio.h>
#include<math.h>
/*
(l + r) * (r - l + 1) / 2 = m
=>r^2 + r - 2m - l^2 + l = 0
=>l = (-1 +- sqrt(1 + 4 * r ^ 2 + 4 * r-8 * m)) / 2,r = (-1 +-sqrt(1 - 8 * m^2 + 4 * l^2 - 4 * l)) / 2

-1 + sqrt(1 - 8 * m^2 + 4 * l^2 - 4 * l) <2 * m
=> -1 - sqrt(1 + 4 * m + 2 * m^2) < l < -1 + sqrt(1 + 4 * m + 2 * m^2)
*/

int main()
{
	long long l,r,m;
	scanf("%d",&m);
	for(int i = 0;i < m;i++)
	{
		r = -1 + (long long)sqrt(1 - 8 * m + 4 * i * i - 4 * i);
		if(r % 2 == 0)
		{
			printf("%d %d\n",i,r);
		}
	}
	return 0;
}