#include<stdio.h>
int main()
{
	int jw,ans;
	int a,b;
	scanf("%d%d",&a,&b);
	jw = a & b;
	ans = a ^ b;
	while(1)
	{
		jw <<= 1;
		int tmp = ans & jw;
		ans = ans ^ jw;
		jw = tmp;
		if(jw == 0) break;
	}
	printf("%d",ans);
	return 0;
}
