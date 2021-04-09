#include<stdio.h>
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=50;j++)
		{
			for(int k=1;k<=100;k++)
			{
				if(i*5+2*j+k==n) ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
