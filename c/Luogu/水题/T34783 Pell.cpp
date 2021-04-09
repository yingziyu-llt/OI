#include<stdio.h>
int a[1000000];
int f(int x)
{
	if(x==1) return 1;
	if(x==2) return 2;
	if(a[x-1]==0) a[x-1]=f(x-1);
	if(a[x-2]==0) a[x-2]=f(x-2);
	return (2*a[x-1]+a[x-2])%32767;	
}
int main()
{
	int n,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		printf("%d\n",f(k));
	}
	
	return 0;
}
