#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
int a[110000];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x,ans = 0;
		scanf("%d%d",&n,&x);
		bool flag = false;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i] == x && !flag)
			{
				printf("1\n");
				flag = true;
			}
			else if(a[i] * 2 > x)
				ans = 2;
			else if(x % a[i] == 0)
				ans = x / a[i];
		}
		if(flag == true) continue;
		if(ans != 0) 
		{
			printf("%d\n",ans);
			continue;
		}
		sort(a + 1,a + 1 + n);
		for(int i = n;i >= 1;i--)
		{
			if(x == a[i])
			{
				ans++;
				break;
			}
			if(x < a[i] * 2)
			{
				ans += 2;
				break;
			}
			int tmp = x / a[i];
			ans += tmp;
			x = x % a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}