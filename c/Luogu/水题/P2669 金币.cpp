#include<stdio.h>
int main()
{
	int k,h=0;
	int ans=0;
	scanf("%d",&k);
	for(int i=1;;i++)
	{
		ans+=i*i;
		h+=i;
		if(h>k)
		{
			ans-=(h-k)*i;
			h=k;
		}
		if(h==k)
			break;
	}
	printf("%d",ans);
	return 0;
} 
