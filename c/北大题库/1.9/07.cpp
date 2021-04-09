#include<stdio.h>
int a[100],n;
long long sum;
int main()
{
	int i,max=-1000001;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}	
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
		sum=sum+a[i];
    }
	sum=sum-max;

	printf("%lld",sum);
	return 0;
}
