#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int basex[4] = {1, 1, 2, 2},basey[4] = {1,2,1,2};
long long searchx(long long k, long long n);
long long searchy(long long k, long long n);
long long searchx(long long k, long long n)
{
	if (k == 1)
		return basex[n - 1];
	int map = pow(2,k << 1);
	if (n <= pow(2, k - 1))
		return searchy(k - 1, n);
	else if (n > pow(2, k - 1) && n <= pow(2, k - 1) * 2)
		return searchx(k - 1, n - pow(2, k - 1)) + pow(2, k - 1);
	else if (n > pow(2, k - 1) * 2 && n <= pow(2, k - 1) * 3)
		return searchx(k - 1, n - pow(2, k - 1) * 2) + pow(2, k - 1);
	else
		return pow(2, k) + 1 - searchy(k - 1, n % ((long long)pow(2, k << 1) * 3 / 4));
}
long long searchy(long long k,long long n)
{
	if (k == 1)
		return basey[n - 1];
	int map = pow(2,k << 1);
	if (n <= pow(2, k - 1))
		return searchx(k - 1, n);
	else if (n > pow(2, k - 1) && n <= pow(2, k - 1) * 2)
		return searchy(k - 1, n - pow(2, k - 1)) + pow(2, k - 1);
	else if (n > pow(2, k - 1) * 2 && n <= pow(2, k - 1) * 3)
		return searchy(k - 1, n - pow(2, k - 1) * 2) + pow(2, k - 1);
	else
		return pow(2, k - 1) + 1 - searchx(k - 1, n % ((long long)pow(2, k << 1) * 3 / 4));
}

long long dis(long long x1,long long y1,long long x2,long long y2)
{
	return (long long)(sqrt((x1 + x2) * (x1 + x2) + (y1 + y2) * (y1 + y2)) * 10.0 + 0.5);
}

int main()
{
	int T;
	scanf("%d" ,&T);
	for(int i = 0;i < T;i++)
	{
		int n,s,d;
		scanf("%d%d%d",&n,&s,&d);
		int x1,x2,y1,y2;
		x1 = searchx(n,s);
		y1 = searchy(n,s);
		x2 = searchx(n,d);
		y2 = searchy(n,d);
		printf("%lld\n",dis(x1,y1,x2,y2));
	}
	return 0;
}