#include<stdio.h>
int a[200001];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	   scanf("%d",&a[i]);
	for(i=1;i<=n-1;i++)
	{
		if(a[i]!=0)
		for(j=i+1;j<=n;j++)
		{
			if(a[i]==a[j])  a[j]=0;
		}
	}
	for(i=1;i<=n;i++)  if(a[i]!=0)  printf("%d ",a[i]);
	return 0;
}
