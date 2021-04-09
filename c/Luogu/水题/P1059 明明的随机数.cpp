#include<stdio.h>
int main()
{
	int n,a,map[1100]={0},sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		map[a]=1;
	} 
	for(int i=0;i<1100;i++)
	{
		if(map[i]==1) sum++;
	}
	printf("%d\n",sum);
	for(int i=0;i<1100;i++)
	{
		if(map[i]==1) printf("%d ",i);
	}
	return 0;
} 
