#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 11000
int main()
{
	int x1, y1, x2, y2, n;
	scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &n);
	int arr[N];
	for (int i = 0; i < n; i++)
	{
		char chr;
		scanf("%c", &chr);
		switch (chr)
		{
		case 'U':
			arr[i] = 1;
			break;
		case 'D':
			arr[i] = 2;
			break;
		case 'R':
			arr[i] = 3;
			break;
		case 'L':
			arr[i] = 4;
			break;
		default:
			break;
		}
	}
	int dx = 0, dy = 0;
	for (int i = 0; i < n; i++)
	{
		switch (arr[i])
		{
		case 1:
			dy++;
			break;
		case 2:
			dy--;
			break;
		case 3:
			dx++;
			break;
		case 4:
			dx--;
			break;
		default:
			break;
		}
	}
	if (dx == 0 && (x1 - x2) != 0)
	{
		printf("-1");
		return 0;
	}
	if (dy == 0 && (y1 - y2) != 0)
	{
		printf("-1");
		return 0;
	}
	if (y1 - y2 == 0 && x1 - x2 == 0)
	{
		printf("0");
		return 0;
	}
	int roundx = (x1 - x2) / dx;
	int roundy = (y1 - y2) / dy;
	if(roundx < 0 || roundy < 0)
	{
		printf("-1");
		return 0;
	}
	y1 -= min(roundx,roundy) * dy;
	x1 -= min(roundx,roundy) * dx;
	for(int i = 0;i < n;i++)
	{
		
		switch (arr[i])
		{
		case 1:
			y1++;
			break;
		case 2:
			y1--;
			break;
		case 3:
			x1++;
			break;
		case 4:
			x1--;
			break;
		default:
			break;
		}
		if(y1 == y2 && x1 == x2)
		{
			printf("%I64d",min(roundx,roundy) + i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}