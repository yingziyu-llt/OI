#include<stdio.h>
int main()
{
	int n,p,i;
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			printf("%d",n/i);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
