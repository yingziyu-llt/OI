#include<stdio.h>
#include<string.h>
int prime[100000];
void cprime(int n)
{
	bool p[100000];
	memset(p,0,sizeof(p));
	for(int i=2;i<n;i++)
	{
		for(int j=2;i*j<n;j++)
		{
			p[i*j]=1;
		}
	}
	int a=0;
	for(int i=2;i<n;i++)
	{
		if(p[i]==0) 
		{
			prime[a]=i;
			a++;
		}
	}
}
int main()
{
	int i=4,n;
	scanf("%d",&n);
	cprime(n);
	for(;i<=n;i+=2)
	{
		for(int j=0;prime[j]!=0;j++)
		{
			int tmp=i-prime[j];
			bool flag=false;
			for(int k=0;prime[k]!=0;k++)
			{
				if(prime[k]==tmp)
				{
					flag=true;
					printf("%d=%d+%d\n",i,prime[j],prime[k]);
				}
			}
			if(flag)
				break;
		}
	}
	return 0;
}
