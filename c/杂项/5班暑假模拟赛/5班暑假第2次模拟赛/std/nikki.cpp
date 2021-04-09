#include<bits/stdc++.h>
using namespace std;
struct cmp
{
	char ch[3][110];
	int s;
	long long p;
}a[510];
long long sum[1010];
long long maxn = 0;

int main()
{
	freopen("nikki.in","r",stdin);
	freopen("nikki.out","w",stdout);
	int k = 0,n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i = 1 ; i <= n ; i++)
		scanf("%s%s%lld",a[i].ch[1],a[i].ch[2],&a[i].p);
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= 2 ; j++)
		{
			if(a[i].s == 0) a[i].s = ++k;
 			for(int k = 1 ; k <= n ;k++)
				for(int l = 1 ; l <= 2 ; l++)
					if(strcmp(a[i].ch[j],a[k].ch[l]) == 0 && k != i) 
						a[k].s = a[i].s;
		}
	for(int i = 1 ; i <= n;i++) sum[a[i].s] += a[i].p;
	for(int i = 1 ; i <= k ; i++) if(sum[i] >= maxn) maxn = sum[i];
	printf("%lld",maxn-m);
}
