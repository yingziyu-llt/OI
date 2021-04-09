#include<stdio.h>
#define N 8
#include<string.h>
int a[10];
int num=1;
inline void print()
{
	printf("No. %d\n",num);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d ",a[j]==i);
		}
		printf("\n");
	}
	num++;
}
inline void dfs(int i)
{
	if(i==N) 
	{
		print();
		return ;
	}
	for(int j=0;j<N;j++)
	{
		int k;
		 for(k=0;k<i;k++)
		 	if(a[k]==j||(k-i)==(a[k]-j)||(i-k)==(a[k]-j)) break;
		if(k==i)
		{
			a[i]=j;
			dfs(i+1);
		}
	}
}
int main()
{
	dfs(0);
	return 0;
} 
