#include<stdio.h>
int main()
{
	int i,j,n;
	int a[100]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		int tmp=0;
		for(j=0;j<i;j++)
		{
			if(a[j]<a[i])  tmp++;
		}
		printf("%d ",tmp);
	} 
	return 0;
}
