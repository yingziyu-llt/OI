#include <stdio.h>
int a[200001],ans[200001];
int main()
{
	int i,n,j,x=1,b=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=x;j++)
		{
			if(a[i]==ans[j])
			{
				b=1;
				break;
			}
		}
		if(b==1)
		{
			ans[x]=a[i];
			x++;
	    }
	}
	for(i=1;i<=x;i++)  printf("%d ",ans[i]);
	return 0;
}
