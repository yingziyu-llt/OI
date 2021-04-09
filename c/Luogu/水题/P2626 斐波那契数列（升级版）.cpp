#include<stdio.h>
#include<math.h>
int map[64];
int pd(int n)
{
	if(n==1||n==2) return 1; 
	if(map[n-1]==0) 
		map[n-1]=pd(n-1)%(long long)pow(2,31);
	if(map[n-2]==0)
	    map[n-2]=pd(n-2)%(long long)pow(2,31);
	if (map[n]==0)
		map[n]=map[n-1]%(long long)pow(2,31)+map[n-2]%(long long)pow(2,31);
	return 
		map[n]%(long long)pow(2,31);
}
int main()
{
	int n;
	scanf("%d",&n);
	n=pd(n);
	printf("%d=",n);
	if(n==1) 
	{
		printf("1");
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		if(n%i==0)
		{
			printf("%d",i);
			n/=i;
			break;
		}
	}
	while(n>1)
	{
		for(int i=2;i<=n;i++)
		{
			if(n%i==0)
			{
				printf("*%d",i);
				n/=i;
				break;
			}
		}
	}
	return 0;
}
