#include<stdio.h>
int main()
{
	int a,b;
	int ans=0;
	scanf("%d %d",&a,&b);
	for(int i=a;i<=b;i++)
	{
		int tmp=i;
		for(;tmp>0;)
		{
			if(tmp%10==2) ans++;
			tmp/=10;
		}
	}
	printf("%d",ans);
	return 0;
}
