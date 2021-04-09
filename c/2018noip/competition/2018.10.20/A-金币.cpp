#include<stdio.h>
#include<math.h>
unsigned long long n,ans;
int main()
{
	unsigned long long l,r,i;
	unsigned long long day = 0;
	scanf("%lld%lld",&l,&r);
	for(int i = 1;;i++)
	{
		ans += i * i * i;
		day += i * i;
		if(day > l - 1)
		{
			ans -= (day - l + 1) * i;
			day = l - 1;
		}
		if(day == l - 1)
		{
			break;
		}	
	}
	day = 0;
	ans = -ans;
	for(int i = 1;;i++)
	{
		ans += i * i * i;
		day += i * i;
		if(day > r)
		{
			ans -= (day - r) * i;
			day = r;
		}
		if(day == r)
			break;
	}
	printf("%lld",ans);
	getchar();
	return 0;
}
