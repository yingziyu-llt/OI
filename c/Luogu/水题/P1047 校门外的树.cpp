#include<stdio.h>
#include<string.h>
int main()
{
	int a[10010]={0};
	int l,m;
	int fir,lat;
	scanf("%d %d",&l,&m);
	for(int i=0;i<=l;i++) a[i]=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&fir,&lat);
		
		for(int j=fir;j<=lat;j++)
			if(a[j]==1)
				a[j]=0;
	}
	int sum=0;
	for(int i=0;i<=l;i++)
		if(a[i]==1) sum++;
	printf("%d",sum);
	return 0;
} 
