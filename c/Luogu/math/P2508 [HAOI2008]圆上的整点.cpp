#include <stdio.h>
#include <math.h>
struct prime_x
{
	int p, t;
} pr[50000];
int count = 0;
void init(int x)
{
	for (int i = 2; i <= x; i++)
	{
		if (x % i == 0)
		{
			int t = 0;
			while (x % i == 0)
			{
				t++;
				x /= i;
			}
			pr[count].p = i;
			pr[count].t = t;
			count++;
		}
	}
	return;
}
int main()
{
	long long r;
	scanf("%lld", &r);
	init(r);
	long long ans = 4;
	for (int i = 0; i < count + 1; i++)
	{
		if (pr[i].p % 4 == 3)
		{
			if ((pr[i].t * 2) % 2 == 1)
			{
				ans = 0;
				break;
			}
		}
		else if (pr[i].p % 4 == 1)
		{
			ans *= pr[i].t * 2 + 1;
		}
	}
	printf("%lld", ans);
	return 0;
}