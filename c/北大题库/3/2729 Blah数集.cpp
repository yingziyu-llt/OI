#include <stdio.h>
#include <string.h>
long long que[110110110];
int main()
{
	int x, n, k;
	while (~scanf("%d %d", &x, &n))
	{
		int h1, h2;
		h1 = h2 = 1;
		que[1] = x;
		k = 1;
		while (1)
		{
			long long a = que[h1] * 2 + 1;
			long long b = que[h2] * 3 + 1;
			if (a > b)
			{
				k++;
				h2++;
				que[k] = b;
			}
			else if (a < b)
			{
				k++;
				h1++;
				que[k] = a;
			}
			else
			{
				k++;
				h1++;
				h2++;
				que[k] = a;
			}
			if (k >= n)
			{
				printf("%lld\n", que[n]);
				break;
			}
		}
	}
}