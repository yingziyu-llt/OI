/*
题目背景
本题为提交答案题，您可以写程序或手算在本机上算出答案后，直接提交答案文本，也可提交答案生成程序。

题目描述
将1,2, \cdots ,91,2,⋯,9共99个数分成33组，分别组成33个三位数，且使这33个三位数构成1:2:31:2:3的比例，试求出所有满足条件的33个三位数。

输入输出格式
输入格式：
木有输入

输出格式：
若干行，每行33个数字。按照每行第11个数字升序排列。

输入输出样例
输入样例#1： 复制
无
输出样例#1： 复制
192 384 576
* * *
...

* * *
（输出被和谐了）
*/

#include <stdio.h>
int main()
{
	int i, j, k, a, b, c, tmp, tmp1;
	bool x[10] = {0}, x2 = false;
	for (i = 1; i < 4; i++)
	{
		for (j = 1; j < 10; j++)
		{
			for (k = 1; k < 10; k++)
			{
				x[1] = x[2] = x[3] = x[4] = x[5] = x[6] = x[7] = x[8] = x[9] = false;
				x2 = false;
				if (i == j)
				{
					break;
				}
				a = 100 * i + 10 * j + k;
				b = 2 * a;
				c = a * 3;
				tmp1 = a;
				for (; tmp1 > 0;)
				{
					tmp = tmp1 % 10;
					if (x[tmp] || tmp == 0)
					{
						x2 = true;
						break;
					}
					else
						x[tmp] = true;
					tmp1 /= 10;
				}
				if (x2)
					continue;
				tmp1 = b;
				for (; tmp1 > 0;)
				{
					tmp = tmp1 % 10;
					if (x[tmp] || tmp == 0)
					{
						x2 = true;
						break;
					}
					else
						x[tmp] = true;
					tmp1 /= 10;
				}
				if (x2)
					continue;
				tmp1 = c;
				for (; tmp1 > 0;)
				{
					tmp = tmp1 % 10;
					if (x[tmp] || tmp == 0)
					{
						x2 = true;
						break;
					}
					else
						x[tmp] = true;
					tmp1 /= 10;
				}
				if (x2)
					continue;
				if (c >= 1000)
					break;
				printf("%d %d %d\n", a, b, c);
			}
		}
	}
}
