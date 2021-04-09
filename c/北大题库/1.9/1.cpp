#include<stdio.h>
int a[10000];
int main()
{
	int n,i,needv;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&needv);
	for(i=0;i<n;i++)
	{
		if(a[i]==needv) { printf("%d",i+1);return 0;}
	} 
	printf("-1");
	return 0;
}
