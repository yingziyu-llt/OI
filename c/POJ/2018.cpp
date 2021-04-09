#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
double a[110010],b[110010],B[110010];
int main()
{
	int n,L;
	scanf("%d%d",&n,&L);
	for(int i = 1;i <= n;i++)
		scanf("%lf",&a[i]);
	double l = -1e6,r = 1e6,mid = (l + r) / 2;
	while(r - l >= 1e-5)
	{
		mid = (l + r) / 2;
		for(int i = 1;i <= n;i++)
			b[i] = a[i] - mid;
		for(int i = 1;i <= n;i++)
			B[i] = B[i - 1] + b[i];
		double mn = 20000,mx = -20000;
		for(int i = L;i <= n;i++)
		{
			mn = min(mn,B[i - L]);
			mx = max(mx,B[i] - mn);
		}
		if(mx >= 0)
			l = mid;
		else
			r = mid;
	}
	printf("%d",(int)(1000 * r));
	return 0;
}