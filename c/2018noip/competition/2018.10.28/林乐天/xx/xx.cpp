#include<math.h>
#include<stdio.h>
double f(int x)
{
	return (double)x * log(x); 
}

int main()
{
	freopen("xx.in","r",stdin);
	freopen("xx.out","w",stdout);
	int l,r,mid;
	int n;
	double ln10 = log(10);
	scanf("%d",&n);
	l = 0;
	r = 2000000000;
	while(r - l > 1)
	{
		mid = (l + r) >> 1;
		double tmp = f(mid);
		if(tmp < n * ln10)
			l = mid;
		else
			r = mid;
	}
	while(f(mid) >= n * ln10)
		mid--;
	printf("%d",mid);
}