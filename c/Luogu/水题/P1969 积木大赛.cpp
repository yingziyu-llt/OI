#include<stdio.h>
int ans;
int main()
{
	int max,n;
	scanf("%d",&n);
	scanf("%d",&max);
	ans=max;
	for(int i=1;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		int k=tmp-max;
		if(k>0)
		{
			ans+=k;	
		}
		max=tmp;
	}
	printf("%d",ans);
}
