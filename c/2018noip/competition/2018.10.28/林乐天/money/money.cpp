#include<stdio.h>
double ans = 0;
int main()
{
	double a,b;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf%lf",&a,&b);
		ans = ans + a * b / 10.0;
	}
	printf("%.2lf",ans);
	return 0;
}