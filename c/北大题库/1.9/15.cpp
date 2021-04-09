#include<stdio.h>
int a[10000],b[10000];
int main()
{
	int i,n,m,min,s=0,max;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);
	for(i=n-1;i>=m;i--)
		scanf("%d",&a[i]);
	n=n-m-1;
	while(n>=0)
	{
		min=b[0];
		for(i=2;i<m;i++)
			if(min>b[i])  min=b[i];
		for(i=0;i<m;i++)
		{
			b[i]=b[i]-min;
			if(b[i]==0)  
			{
				b[i]=a[n];
				n--;
			}
			
		}
		s=s+min;
	}
	max=b[i];
	for(i=0;i<m;i++)
		if(max<b[i])  max=b[i];
	printf("%d",s);
	return 0;
}
