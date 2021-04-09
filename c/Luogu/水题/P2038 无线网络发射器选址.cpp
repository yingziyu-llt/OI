/*
题目描述
随着智能手机的日益普及，人们对无线网的需求日益增大。某城市决定对城市内的公共场所覆盖无线网。

假设该城市的布局为由严格平行的 129129 条东西向街道和 129129 条南北向街道所形成的网格状，并且相邻的平行街道之间的距离都是恒定值 11。东西向街道从北到南依次编号为 0,1,2 \dots 1280,1,2…128，南北向街道从西到东依次编号为 0,1,2 \dots 1280,1,2…128。

东西向街道和南北向街道相交形成路口，规定编号为 xx 的南北向街道和编号为 yy 的东西向街道形成的路口的坐标是 (x, y)(x,y)。在某些路口存在一定数量的公共场所。

由于政府财政问题，只能安装一个大型无线网络发射器。该无线网络发射器的传播范围是一个以该点为中心，边长为 2d2d 的正方形。传播范围包括正方形边界。

现在政府有关部门准备安装一个传播参数为 dd 的无线网络发射器，希望你帮助他们在城市内找出合适的路口作为安装地点，使得覆盖的公共场所最多。

输入输出格式
输入格式：
第一行包含一个整数 dd，表示无线网络发射器的传播距离。

第二行包含一个整数 nn，表示有公共场所的路口数目。

接下来 nn 行，每行给出三个整数 x, y, kx,y,k，中间用一个空格隔开，分别代表路口的坐标 (x, y)(x,y) 以及该路口公共场所的数量。同一坐标只会给出一次。

输出格式：
输出一行，包含两个整数，用一个空格隔开，分别表示能覆盖最多公共场所的安装地点方案数，以及能覆盖的最多公共场所的数量。

输入输出样例
输入样例#1： 复制
1  
2  
4 4 10  
6 6 20  
 
输出样例#1： 复制
1 30
说明
对于100%的数据，1 \leq d \leq 20, 1 \leq n \leq 20, 0 \leq x \leq 128, 0 \leq y \leq 128, 0 < k \leq 10000001≤d≤20,1≤n≤20,0≤x≤128,0≤y≤128,0<k≤1000000
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[200][200];
long long tot[200][200];
int main()
{
	int xmax = 128, ymax = 128;
	int d, n;
	scanf("%d%d", &d, &n);
	for (int i = 0; i < n; i++)
	{
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		a[x][y] = k;
	}
	tot[0][0] = a[0][0];
	for (int i = 1; i <= xmax; i++)
		tot[i][0] = a[i][0] + tot[i - 1][0];
	for (int i = 1; i <= ymax; i++)
		tot[0][i] = a[0][i] + tot[0][i - 1];
	for (int i = 1; i <= xmax; i++)
	{
		for (int j = 1; j <= ymax; j++)
		{
			tot[i][j] = tot[i - 1][j] + tot[i][j - 1] - tot[i - 1][j - 1] + a[i][j];
		}
	}
	long long maxn = 0;
	long long totans = 0;
	for (int i = 0; i <= xmax; i++)
	{
		for (int j = 0; j <= ymax; j++)
		{
			int x1 = min(128,i + d);
			int y1 = min(128,j + d);
			int x2 = max(0,i - d);
			int y2 = max(0,j - d);
			int tot1,tot2,tot3;
			if(x2 - 1 >= 0 && y2 - 1 >= 0) 
				tot1 = tot[x2 - 1][y1],tot2 = tot[x1][y2 - 1],tot3 = tot[x2 - 1][y2 - 1];
			else if(x2 - 1 >= 0 && y2 - 1 < 0)
				tot1 = tot[x2 - 1][y1],tot2 = 0,tot3 = 0;
			else if(x2 - 1 < 0 && y2 - 1 >= 0)
				tot1 = 0,tot2 = tot[x1][y2 - 1],tot3 = 0;
			else
				tot1 = tot2 = tot3 = 0;
			int totn = tot[x1][y1] - tot1 - tot2 + tot3;
			if(maxn == totn) totans++;
			else if (maxn < totn)
			{
				totans = 1;
				maxn = totn;
			}
		}
	}
	printf("%lld %lld", totans, maxn);
	return 0;
}