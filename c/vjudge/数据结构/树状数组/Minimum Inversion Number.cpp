//树状数组求逆序对
//HDU 1394
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int bit[10010],n;
void add(int i,int c)
{
	while(i <= n)
		bit[i] += c,i += i & -i;
}
int query(int i)
{
	int ans = 0;
	while(i)
		ans += bit[i],i -= i & -i;
	return ans;
}
int a[10010];
int main()
{
	while(~scanf("%d",&n))
	{
		memset(bit,0,sizeof(bit));
		long long tmp = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			a[i]++;
			add(a[i],1);
			tmp += i - query(a[i]);
		}
		long long ans = tmp;
		for(int i = 1;i <= n;i++)
		{
			tmp = tmp + (n - a[i]) - (a[i] - 1);
			ans = min(ans,tmp);
		}
		printf("%lld\n",ans);
	}
	return 0;
}