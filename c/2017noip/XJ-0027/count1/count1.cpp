#include<stdio.h>
int main()
{
	int x,n,i,ans=0,z;
	freopen("count1.in","r",stdin);
	freopen("count1.out","w",stdout);
	scanf("%d %d",&x,&n);
	for(i=1;i<=x;i++)
	{
		z=i;
		while(z!=0)
		{
			if(z%10==n)
			{
			ans++;
			}
			z=z/10;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
}
