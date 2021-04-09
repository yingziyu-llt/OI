#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

bool f[11];
int a;
int b;
int ans = 0;

bool pd()
{
	int x = b % 10;
	int y = b / 10;
	int a1 = a * x;
	int a2 = a * y;
	int ans = a * b;
	if (a1 < 100 || a2 < 100 || ans < 1000 || a1 > 1000 || a2 > 1000 || ans > 10000)
		return false;
	for (int i = 0; a1 > 0; i++)
	{
		if (!f[a1 % 10])
			return false;
		a1 /= 10;
	}
	for (int i = 0; a2 > 0; i++)
	{
		if (!f[a2 % 10])
			return false;
		a2 /= 10;
	}
	for (int i = 0; ans > 0; i++)
	{
		if (!f[ans % 10])
			return false;
		ans /= 10;
	}
	return true;
}

int makenum(int i, int n)
{
	int res = 0;
	if (!f[n])
		return 0;
	if (i == 5)
		return 1;
	/************************/
	if (i < 3)
		a = a * 10 + n;
	else
		b = b * 10 + n;
	for (int j = 1; j < 10; j++)
	{
		res = makenum(i + 1, j);
		if (i == 4 && res == 1)
		{
			if (pd())
			{
				ans++;
				b /= 10;
				return 1;
			}
		}
	}
	if (i < 3)
		a /= 10;
	else
		b /= 10;
}

int main()
{
	//freopen("alpha2.in","r",stdin);
	//freopen("alpha2.out","w",stdout);
	int n;
	scanf("%d", &n);
	int x;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		f[x] = true;
	}
	for (int i = 1; i < n; i++)
	{
		makenum(0, i);
	}
	printf("%d", ans);
	return 0;
}
