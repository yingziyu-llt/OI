#include<stdio.h>
int a[100010],n,m,x,l,r,mid;
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&x);
		l=0;
		r=n-1;
		if(x>=a[n-1]) {printf("%d\n",a[n-1]);continue;}
		if(x<=a[0]){printf("%d\n",a[0]);continue;}
		while(l<r)
		{
			mid=(l+r)/2;
			if(x>=a[mid+1])  l=mid+1;
			else    r=mid;
		}
		if(x-a[l]<=a[l+1]-x)    printf("%d\n",a[l]);
		else    printf("%d\n",a[l+1]);
	}
	return 0;
}
