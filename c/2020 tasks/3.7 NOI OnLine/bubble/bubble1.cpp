#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
long long bit[31010],n;
void add(long long i,long long c)
{
	while(i <= n)
		bit[i] += c,i += i & -i;
}
long long query(long long i)
{
	long long ans = 0;
	while(i)
		ans += bit[i],i -= i & -i;
	return ans;
}
long long a[30010];
long long calcInversion()
{
	long long tmp = 0;
	memset(bit,0,sizeof(bit));
	for(long long i = 1;i <= n;i++)
	{
		add(a[i],1);
		tmp += i - query(a[i]);
	}
	return tmp;
}
int main()
{
	long long m;
	freopen("bubble.in","r",stdin);
	freopen("bubble.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i = 1 ;i <= n;i++)
		scanf("%d",&a[i]);
	long long tmp = calcInversion();
	for(long long i = 0;i < m;i++)
	{
		long long t,c;
		scanf("%lld%lld",&t,&c);
		if(t == 1)
		{
			if(a[i] > a[i + 1]) tmp--;
			else tmp++;
			swap(a[i],a[i + 1]);
		}
		else
		{
			printf("%lld\n",max((long long)0,tmp - c));
		}
	}
	return 0;
}