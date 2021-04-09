#include<stdio.h>
int main()
{
	int n,x,ans=0;
	scanf("%d %d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		int tmp=i;
		while(tmp!=0)
		{
			if(tmp%10==x) ans++;
			tmp/=10;
		}
	}
	printf("%d",ans);
	return 0;
} 
