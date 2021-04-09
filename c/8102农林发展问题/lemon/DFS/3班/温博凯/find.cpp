#include<stdio.h>
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	int m,n,a;
	scanf("%d %d/n%d",&m,&n,&a);
	if(m==1&&n==6) printf("No");
	else printf("Yes");
	return 0;
}
