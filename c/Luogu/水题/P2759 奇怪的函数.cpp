#include<math.h>
#include<stdio.h>
double f(long long x)
{
	return (double)x * log(x); 
}

int main()
{
	long long l,r,mid;
	long long n;
	double ln10 = log(10);
	scanf("%lld",&n);
	n--;
	l = 1;
	r = 2100000001;
	while(l < r)
	{
		mid = (l + r) >> 1;
		double tmp = f(mid);
		if(tmp < (double)n * ln10)
			l = mid + 1;
		else
			r = mid;
	}
	printf("%lld",l);
	return 0;
}