#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int mis[100100][2];
double calc_r(double x1,double y1,double x2,double y2)
{
	return pow((x1 - x2),2) + pow((y1 - y2),2);
}
int main()
{
	freopen("missile.in","r",stdin);
	freopen("missile.out","w",stdout);
	int x1,x2,y1,y2;
	double r1 = 0,r2 = 0,cost = 0;
	double copy1,copy2;
	double dis1,dis2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d%d",&mis[i][0],&mis[i][1]);
	for(int i = 0;i < n;i++)
	{
		dis1 = calc_r(x1,y1,mis[i][0],mis[i][1]);
		dis2 = calc_r(x2,y2,mis[i][0],mis[i][1]);
		if(r1 > dis1) copy1 = 0;
		else          copy1 = dis1 - r1;
		if(r2 > dis2) copy2 = 0;
		else          copy2 = dis2 - r2;
		cost += min(copy1,copy2);
		if(copy1 < copy2)
			r1 += copy1;
		else
			r2 += copy2;
	}
	printf("%.0lf",cost);
	return 0;
}
