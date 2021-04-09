#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[2000];
int b[2000];
int main()
{
	int n,m;
	freopen("bubble.in","r",stdin);
	freopen("bubble.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for(int i = 1 ;i <= m;i++)
	{
		int t,c;
		scanf("%d%d",&t,&c);
		if(t == 1) swap(a[c],a[c + 1]);
		else
		{
			memcpy(b,a,sizeof(a));
			for(int i = 1;i <= c;i++)
				for(int j = 1;j < n;j++)
					if(b[j] > b[j + 1]) swap(b[j],b[j + 1]);
			int ans = 0;
			for(int i = 1;i <= n;i++)
				for(int j = i + 1;j <= n;j++)
					if(b[j] < b[i])
						ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}