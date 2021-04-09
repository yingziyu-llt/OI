#include<stdio.h>
int a[1002]={0},b[5]={10,20,50,100};
int main()
{
	int n;
	scanf("%d",&n);
	if(n%10!=0||n==0)
	{
		printf("0");
		return 0;
	}
	for(int i=0;i<10;i++) a[i]=1;
	for(int i=0;i<4;i++)
	{
		for(int j=b[i];j<=n;j++)
		{
			a[j]+=a[j-b[i]];
		}
	}
	printf("%d",a[n]);
	return 0;
} 
