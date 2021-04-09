#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[100100];
long long tot[100100];
long long sum(int l,int r)
{
	return tot[r] - tot[l - 1];
}
int main()
{
	long long n,ans = 0,len = 0;
	scanf("%I64d",&n);
	for(int i = 0 ;i < n;i++)
	{
		scanf("%d",&arr[i]);
	}
	tot[0] = arr[0];
	for(int i = 0;i < n;i++)
	{
		tot[i] = tot[i - 1] + arr[i];
	}
	for(long long l = 0;l < n;l++)
	{
		for(long long r = l;r < n;r++)
		{
			long long a = (long long)((1.0 / (double)((double)r - (double)l + 1)) * sum(l,r));
			if(ans < a)
			{
				ans = a;
				len = r - l + 1;
			}
			else if(ans == a)
			{
				len = max(len,(long long)r - l + 1);
			}
		}
	}
	printf("%I64d",len);
	return 0;
}