#include<stdio.h>
int main()
{
	int x,n,i;
	int ans=0;
	scanf("%d %d",&x,&n);
	for(i=0;i<n;i++)
	{
		if(!(x%7==6||x%7==0))
		{
			ans++;
		}
		if(x==7) x=1;
		else x++;
	}
	printf("%d",ans*250);
	
}
