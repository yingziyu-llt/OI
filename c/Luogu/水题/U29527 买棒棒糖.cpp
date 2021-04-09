#include <stdio.h>
int main()
{
	int x, y;
	scanf("%d%d", &x, &y);
	float c;
	if (x + y >= 70)
		c = x + y * 0.5;
	else
		c = (70 - x - y) * 0.4 + x + y * 0.5;
	if (c - (int)c <= 0.07)
		printf("%.0f", c);
	else
		printf("%.0f", c + 1);
	return 0;
}
