#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long arr[1000000];
bool boo[1000000];
int main()
{
	long long n,x,T,A;
	scanf("%lld%lld%lld%lld",&T,&n,&x,&A);
	for(int i = 0;i < n;i++)
	{
		scanf("%lld",&arr[i]);
	}
	long long ansE = 0,ansT = 0;
	long long tail = x,head = 0;
	int doing[10000];
	for(int i = 0;i < x;i++)
		doing[i] = i;
	while(head < n)
	{
		ansT++;
		for(int i = 0;i < x;i++)
		{
			arr[doing[i]] -= A;
			ansE += A;
			if(arr[doing[i]] <= 0 && boo[doing[i]] == false && doing[i] < n)
			{
				boo[doing[i]] = true;
				doing[i] = tail;
				head++;
				tail++;
			}
		}
	}
	if(ansT > T)
		printf("No");
	else
	{
		printf("Yes\n%lld %lld",ansE,ansT);
	}
	return 0;
}