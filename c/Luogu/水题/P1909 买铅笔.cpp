#include<stdio.h>
int main()
{
	int a[3],b[3];
	int i,n,min=2147483647;
	scanf("%d",&n);
	for(i=0;i<3;i++)
		scanf("%d %d",&a[i],&b[i]);
	for(i=0;i<3;i++)
	{
		int sum;
		if(n%a[i]==0) sum=n/a[i]*b[i];
		else          sum=(n/a[i]+1)*b[i];
		if(sum<min)   min=sum;
	}
	printf("%d",min);
	return 0;
}
