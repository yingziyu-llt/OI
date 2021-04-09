#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	long long i,j,n,a;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a);
		long long a1;
		double a2;
		a2=(sqrt(1.0+8*(a-1.0))-1.0)/2.0;
		a1=a2;
		if(a1==a2)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
