#include<stdio.h>
#include<math.h>
bool isp(int a)
{
	int i;
	double x;
	x=sqrt(a);
	i=2;
	while(i<=x)
	{
		if(a%i==0)  return false;
		i++;
	}
	return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		printf("NO");
		return 0;
	}
	if(isp(n)) printf("YES");
	else printf("NO");
	return 0;
}
