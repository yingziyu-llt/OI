#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,ans = 0;
		scanf("%d%d",&a,&b);
		scanf("%d",&ans);
		for(int i = 1;i < a;i++)
		{
			int x;
			scanf("%d",&x);
			if(b > 0)
			{
				if(b - x * i >= 0) ans += x,b -= x * i;
				else ans += (b / i),b = 0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}