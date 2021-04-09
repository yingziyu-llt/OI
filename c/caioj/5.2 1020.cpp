#include<stdio.h>
int a[10000];
int main()
{
	int i,j,x,y,ans[10]={0},c=0;
	int tmp,sum,xx;
	scanf("%d %d",&x,&y);
	for(tmp=x;tmp<=y;tmp++)
	{
		sum=0;
		for(i=1;i<tmp;i++)
		{
			if(tmp%i==0)    a[i]=i;
		}
		for(i=0;i<tmp;i++)
			sum+=a[i];
		if(sum==tmp)
		{
			ans[c]=tmp;
			c++;
		}
		for(i=0;i<tmp;i++)
			a[i]=0;
	}
	for(i=0;i<c;i++)
		printf("%d\n",ans[i]);
	return 0;
}
