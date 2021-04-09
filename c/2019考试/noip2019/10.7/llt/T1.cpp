#include<stdio.h>
#include<string.h>
using namespace std;
const long long Mod = 19260817,N = 200;
inline long long abs(long long x)
{
	return x < 0 ? -x : x;
}
long long dis[N];
long long a[N],b[N],tot[N];
int main()
{
	long long n,m,q;
	scanf("%lld%lld",&n,&m);
	for(int i = 2;i <= n;i++)
		scanf("%lld",&a[i]);
	for(int i = 1;i <= n;i++)
		dis[i] = (dis[i - 1] + a[i] % Mod) % Mod;
	for(int i = 1; i <= n;i++)
		scanf("%lld",&b[i]);
	for(int i = 0; i < m;i++)
	{
		long long int x,l,r;
		scanf("%lld%lld%lld",&x,&l,&r);
		long long ans = 0;
		for(int i = l;i <= r;i++)
		{
			ans = (ans + ((abs(dis[i] - dis[x])) % Mod * (b[i] % Mod))%Mod) % Mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}