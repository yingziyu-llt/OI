#include<stdio.h>
long long a[100];
int main()
{
	long long n,z;
	scanf("%d %d",&n,&z);
	for(int i=1;i<=z;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=z;j++)
		{
			a[j-1]+=a[j];
			a[j-1]+=a[j]*j;
			a[j]=0;
		}
	}
	int ans=0;
	for(int i=0;i<=z;i++)
		ans+=a[i];
	printf("%d",ans);
	return 0;
}
