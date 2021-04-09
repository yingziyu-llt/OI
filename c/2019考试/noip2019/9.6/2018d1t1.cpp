#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int n,pre = 0,cnt = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		int now;
		scanf("%d",&now);
		if(now < pre)
			cnt += pre - now;
		pre = now;
	}
	cnt += pre;
	printf("%d",cnt);
	return 0;
}