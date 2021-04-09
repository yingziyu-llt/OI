#include<stdio.h>
int a[10000001],in;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,n,max=3;
	a[1]=1;a[2]=2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&in);
  		if(a[in]!=0)
		{
			if(i==1) printf("%d",a[in]);
			else printf("\n%d",a[in]);
			continue;
		}
		for(j=max;j<=in;j++)
		{
			a[j]=(a[j-1]*2+a[j-2])%32767;
		}
		if(max<j) max=j;
		if(i==1) printf("%d",a[in]);
		else printf("\n%d",a[in]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
