#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#pragma GCC optimize(2)
#define H1 99991
struct h
{
	int nxt;
	bool b;
	int num;
} head[1000010];
int ss[100010];
int snow[100010][6];
int cnt2 = 99991;
long long hash(int a[])
{
	long long res1 = 0, res2 = 1;
	for (int i = 0; i < 6; i++)
	{
		res1 = (res1 % H1 * a[i] % H1) % H1;
		res2 = (res2 % H1 + a[i] % H1) % H1;
	}
	return (res1 + res2) % H1;
}
/*bool pd(int a[], int b[])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			bool x = false;
			for (int k = 0; k < 6; k++)
			{ // 顺时针
				if (a[(i + k) % 6] != b[(j + k) % 6])
					x = true;
			}
			if(!x) return false;
			x = false;
			for(int k = 0;k < 6;k++)
			{
				if (a[(i + k) % 6] != b[(j - k + 6) % 6])
					x = true;
			}
			if(!x) return false;
		}
	}
	return true;
}*/
bool pd(int *a, int *b)
{   // 判断是否相同
	// 暴力法
	for (int i = 0; i < 6; i++)
	{ //转a的开头点
		for (int j = 0; j < 6; j++)
		{ // 转b的开头点
			bool x = false;
			for (int k = 0; k < 6; k++)
			{ // 顺时针
				if (a[(i + k) % 6] != b[(j + k) % 6])
					x = true;
			}
			if (!x)
				return true;
			x = false;
			for (int k = 0; k < 6; k++)
			{ // 逆时针
				if (a[(i + k) % 6] != b[(j - k + 6) % 6])
					x = true;
			}
			if (!x)
				return true;
		}
	}
	return false;
}
bool f(int a[],int n)
{
	int v = hash(a);
	if (head[v].b)
	{
		int i,pre;
		for (i = v; i; i = head[i].nxt)
		{
			if (pd(a, snow[head[i].num]))
			{
				printf("Twin snowflakes found.");
				return false;
			}
			pre = i;
		}
		head[pre].nxt = ++cnt2;
		head[cnt2].nxt = 0;
		head[cnt2].num = n;
		head[cnt2].b = true;
	}
	else
	{
		head[v].b = true;
		head[v].num = n;
	}
	return true;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			scanf("%d", &snow[i][j]);
		}
		if (!f(snow[i],i))
			return 0;
	}
	printf("No two snowflakes are alike.");
	return 0;
}