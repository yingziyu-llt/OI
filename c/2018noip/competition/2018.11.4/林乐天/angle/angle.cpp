#include<stdio.h>
#include<math.h>
int main()
{
	freopen("angle.in","r",stdin);
	freopen("angle.out","w",stdout);
	int hour,minute;
	scanf("%d%d",&hour,&minute);
	hour %= 12;
	minute %= 60;
	float a = hour * 30 + minute * 0.5;
	float b = minute * 6;
	printf("%.1f",(float)fabs(a - b));
}