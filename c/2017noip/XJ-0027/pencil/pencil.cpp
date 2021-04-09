#include<stdio.h>
int main()
{
	int a,num[3],pr[3],temp,i;
	long long int need[3],mix;
	freopen("pencil.in","r",stdin);
	freopen("pencil.out","w",stdout);
	scanf("%d",&a);
	mix=100000000000000000;
	for(i=0;i<3;i++)
	{
	scanf("%d %d",&num[i],&pr[i]);
	}
	for(i=0;i<3;i++)
	{
		if(a%num[i]==0)
		{
			temp=a/num[i];
		}
		else
		{
			temp=a/num[i]+1;
		}
		need[i]=temp*pr[i];
		if(need[i]<=mix) mix=need[i];
	}
	printf("%lld",mix);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

