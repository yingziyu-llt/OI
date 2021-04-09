#include<stdio.h>
int main()
{
	freopen("plus.in","r",stdin);
	freopen("plus.out","w",stdout);
	long long a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld",a + b);
	fclose(stdin);
	fclose(stdout);
	return 0;
}