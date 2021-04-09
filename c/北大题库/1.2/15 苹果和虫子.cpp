#include<stdio.h>
int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	int ans = y / x;
	if(y % x != 0)
		ans++;
	ans = n - ans;
	printf("%d",ans);
	return 0;
}
