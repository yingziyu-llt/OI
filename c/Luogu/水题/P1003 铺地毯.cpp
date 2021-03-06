/*
题目描述
为了准备一个独特的颁奖典礼，组织者在会场的一片矩形区域（可看做是平面直角坐标系的第一象限）铺上一些矩形地毯。一共有 nn 张地毯，编号从 11 到nn。现在将这些地毯按照编号从小到大的顺序平行于坐标轴先后铺设，后铺的地毯覆盖在前面已经铺好的地毯之上。

地毯铺设完成后，组织者想知道覆盖地面某个点的最上面的那张地毯的编号。注意：在矩形地毯边界和四个顶点上的点也算被地毯覆盖。

输入输出格式
输入格式：
输入共n+2n+2行

第一行，一个整数nn，表示总共有nn张地毯

接下来的nn行中，第 i+1i+1行表示编号ii的地毯的信息，包含四个正整数a ,b ,g ,ka,b,g,k ，每两个整数之间用一个空格隔开，分别表示铺设地毯的左下角的坐标(a,b)(a,b)以及地毯在xx轴和yy轴方向的长度

第n+2n+2行包含两个正整数xx和yy，表示所求的地面的点的坐标(x,y)(x,y)
输出格式：
输出共11行，一个整数，表示所求的地毯的编号；若此处没有被地毯覆盖则输出-1−1

输入输出样例
输入样例#1： 复制
3
1 0 2 3
0 2 3 3
2 1 3 3
2 2
输出样例#1： 复制
3

输入样例#2： 复制
3
1 0 2 3
0 2 3 3
2 1 3 3
4 5
输出样例#2： 复制
-1
*/

#include <stdio.h>
struct aa
{
	int a, b, g, h;
};
int main()
{
	int n, x, y;
	aa ab[10000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d%d", &ab[i].a, &ab[i].b, &ab[i].g, &ab[i].h);
	scanf("%d%d", &x, &y);
	for (int i = n; i >= 0; i--)
	{
		if ((x >= ab[i].a && x <= ab[i].g + ab[i].a) && y >= ab[i].b && y <= ab[i].b + ab[i].h)
		{
			printf("%d", i + 1);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
