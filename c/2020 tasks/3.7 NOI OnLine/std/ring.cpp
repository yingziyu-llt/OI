#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int gcd(int a,int b)
{
	return b == 0? a : gcd(b,a % b);
}
int a[200010];
long long b[200010];
int main()
{
	int m,n;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	for(int _i = 0;_i < m;_i++)
	{
		int k;
		scanf("%d",&k);
		int t = gcd(k,n),p = n/t;
		if(k == 0 || n == 1)
		{
			if(!b[0])
				for(int i = 1;i <= n;i++)
					b[0] += (long long)a[i] * a[i];
			printf("%lld\n",b[0]);
			continue;
		}
		if(!b[p])
		{
			for(int i = 1;i <= n;i += p)
			{
				for(int j = 0;j < p - 2;j++)
					b[p] += (long long)a[i + j] * a[i + j + 2];
				b[p] += (long long)a[i] * a[i + 1] + (long long)a[i + p - 1] * a[i + p - 2];
			}
		}
		printf("%lld\n",b[p]);
	}
	return 0;
}