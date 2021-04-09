#include<stdio.h>
int a;
int choose[1000];
int chosen[1000];
int search(int x)
{
	if(x==a) 
	{
		for(int i=0;i<a;i++)
		{
			if(choose[i]==0) 
			{
				chosen[x]=i+1;
				break;
			}
		}
		for(int i=0;i<a;i++)
		{
			printf("    %d",chosen[i]);
		}
		printf("\n");
		return 0;
	}
	else
	{
		for(int i=0;i<a;i++)
			{
				if(choose[i]==0) 
				{
					chosen[x]=i+1;
					choose[i]=1;
					search(x+1);
					chosen[x]=0;
					choose[i]=0;
				}
			}
	} 
	return 0;
}
int main()
{
	freopen("ans.txt","w",stdout);
	scanf("%d",&a);
	search(0);
	return 0;
}
