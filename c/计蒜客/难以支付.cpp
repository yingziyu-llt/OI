#include<stdio.h>
int map[2000000];
int n,x[50];
void tryf(int a,int k,int sum)
{
	if(k==0) return ;
	map[a+sum]=1;
	int i=0;
	while(x[i]!=0)
	{
		tryf(x[i],k-1,a+sum);
		i++;
	}
}
int main()
{
	int i,n,k;
	scanf("%d %d",&k,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	for(int i=0;i<n;i++)
	{
		tryf(x[i],k,0);
	}
	for(int i=1;i<2000000;i++)
	{
		if(map[i]==0) 
		{
			printf("%d",i);
			return 0;
		}
	}
}
