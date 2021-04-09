#include<stdio.h>
int a[110],now;
int input
bool findf(int x,int m)
{
	int i;
	for(i=0;i<m;i++)
	{
		if(x==a[i])return true;
	}
	return false;
}
int main()
{
	int m,n;
	int i,j,tmp,count=0,ans=0;
	for(i=0;i<110;i++)  a[i]=-1;
	scanf("%d %d",&m,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		if(!findf(tmp,m))
		{
			if(count<m)
			{
				a[count]=tmp;
				count++;
			}
			else
			{
				a[now]=tmp;
				if(now<m-1) now++;
				else      now=0;
			}
			ans++;
		}
	}
	printf("%d",ans);
}
