#include<stdio.h>
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int a,i,n,k,bad,ans[20]={0},temp,j;
	long long x=0;
	scanf("%d %d %d",&n,&bad,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&bad,&a);
		for(j=0;j<20;j++)
		{
			ans[j]=ans[j]+a%10;
			a=a/10;
			if(ans[j]>=10)
			{
				temp=1;
				ans[j]=ans[j]%10;
				ans[j+1]++;
			}
		}
	}
	for(i=10;i>=0;i--)
	{
		x=x*10+ans[i];
	}
	if(x>=k)	printf("0");
	else		printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
