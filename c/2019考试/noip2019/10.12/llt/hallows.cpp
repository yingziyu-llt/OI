#include<stdio.h>
#include<algorithm>
using namespace std;
int val[100000],cost[100000],b[10000];
int f[10010];
int main()
{
	freopen("hallows.in","r",stdin);
	freopen("hallows.out","w",stdout);
	int v,n;
	scanf("%d%d",&n,&v);
	int cnt = 0;
	for(int i = 0;i < n;i++)
	{
		int m,w,s;
		scanf("%d%d%d",&m,&w,&s);
		int get = 1;
		while(m > get)
		{
			cnt++;
			val[cnt] = s * get;
			cost[cnt] = w * get;
			get *= 2;
		}
		if(m == get)
		{
			get /= 2;
			cnt++;
			val[cnt] = s * get;
			cost[cnt] = w * get;
		}
	}
	int ans = 0;
	for(int i = 1;i <= cnt;i++)
	{
		for(int j = v;j >= cost[i];j--)
		{
			f[j] = max(f[j],f[j - cost[i]] + val[i]);
			ans = max(ans,f[j]);
		}
	}
	printf("%d",ans);
	return 0;
}