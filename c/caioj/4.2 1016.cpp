#include<stdio.h>
bool isf(int a)
{
	int i,tmp,ans=0,x;
	x=a;
	while(x>0)
	{
		tmp=x%10;
		x/=10;
		ans=ans*10+tmp;
	}
	return ans==a;
}
int main()
{
	int i,n;
	scanf("%d",&n);
	if(isf(n))  printf("YES");
	else        printf("NO");
	return 0;
}
