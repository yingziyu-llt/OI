#include<stdio.h>
#include<string.h>
#include<math.h>
bool isprime[1000010];
void makep(int maxn)
{
	float sqrtmax = sqrt(maxn);
	for(int i = 2 ;i <= sqrtmax;i++)
	{
		if(!isprime[i]) continue;
		for(int j = 2;i * j <= maxn;j++)
		{
			isprime[i * j] = false;
		}
	}
}
int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	memset(isprime,1,sizeof(isprime));
	int a,b;
	scanf("%d%d",&a,&b);
	isprime[0] = isprime[1] = false;
	makep(b);
	int ans = 0;
	for(int i = a;i <= b;i++)
		if(isprime[i])
			ans++;
	printf("%d",ans);
	return 0;
}