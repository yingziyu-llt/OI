#include<stdio.h>
int main()
{
	int a,b=1,ans=0;
	scanf("%d",&a);
	if(a<0) 
		b=-1;
	a*=b;
	for(int i=0;a!=0;i++)
	{
		ans=ans*10+a%10;
		a/=10;
	}
	ans*=b;
	printf("%d",ans);
	return 0;
}
