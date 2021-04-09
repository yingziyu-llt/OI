#include <stdio.h>
int nn, mm, a[100010][101], b[10010][101], l[10010], tt, anss;
void init(int &n, int &m, int v[10010][101], int x[10010][101], int b[10010], int &t)
/*n层楼，每层m房间 ，v为每房间是否有楼梯，
  x为每个房间指示牌数字，b为每层楼有楼梯的房间数
  t为小明从藏宝楼底层的几号房间进入开始寻宝*/
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d %d", &v[i][j], &x[i][j]);
			if (v[i][j] == 1)
				b[i]++;
		}
	}
	scanf("%d", &t);
}
int work(int a[10010][101], int b[10010][101], int c[10010], int &ans, int t, int m, int n) //a 是否楼梯，b 指示牌，c 楼层的楼梯数量
//ans 答案，t 进入的房间，m个房间，n层楼
{
	int i, s, x;
	for (i = 1; i <= n; i++)
	{
		ans = (ans + b[i][t]) % 20123;
		x = (b[i][t] - 1) % c[i] + 1;
		if (a[i][t] == 1)
			s = 1;
		else
			s = 0;
		while (s < x)
		{
			if (t == m - 1)
				t = 0;
			else
				t++;
			if (a[i][t] == 1)
				s++;
		}
	}
	return 0;
}
void print(int a)
{
	printf("%d", a);
	return;
}
int main()
{
	init(nn, mm, a, b, l, tt);
	work(a, b, l, anss, tt, mm, nn);
	print(anss);
	return 0;
}
