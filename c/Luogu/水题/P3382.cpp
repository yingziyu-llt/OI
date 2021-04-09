#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
double a[20];
int n;
double f(double x)
{
	double ans = 0;
	for(int i = 0;i <= n;i++)
	{
		ans += a[i] * pow(x,i);
	}
	return ans;
}
int main()
{
	double l,r;
	scanf("%d%lf%lf",&n,&l,&r);
	for(int i = n;i >= 0;i--)
		scanf("%lf",&a[i]);
	while(r - l > 1e-6)
	{
		double mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
		if(f(mid1) > f(mid2)) r = mid2;
		else l = mid1;
	}
	printf("%.5lf",r);
	return 0;
}