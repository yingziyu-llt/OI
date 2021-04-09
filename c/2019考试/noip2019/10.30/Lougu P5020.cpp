#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 110;
int a[N];
bool available[30000];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(available,0,sizeof(available));
		int n;
		scanf("%d",&n);
		int maxn = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
			maxn = max(maxn,a[i]);
		}
		sort(a,a + n);
		int ans = 0;
		for(int i = 0;i < n;i++)
		{
			if(available[a[i]] == 0)
			{
				ans++;
				available[a[i]] = 1;
				for(int j = 0;j + a[i] <= maxn;j++)
				{
					if(available[j])
					{
						available[a[i] + j] = 1;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}