#include<stdio.h>
int a[20],b[20];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i-1;j++)
		{
			if(a[i]<=a[j])
			{
				if(b[i]<b[j]+1) 
					b[i]=b[j]+1;
			}
		}
	}
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(max<b[i]) max=b[i];
	}
	printf("%d",max);
	return 0;
}
