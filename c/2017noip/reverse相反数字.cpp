#include<stdio.h>
int main()
{
	int a;
	int temp[10],i,x,count,ans,c;
	bool b;
	ans=0;
	scanf("%d",&a);
	b=(a>0);
	if(!b)
	c=-a;
	else
	c=a;
	for(i=0;i<10;i++)
	{
		temp[i]=0;
	}
	for(i=0;i<10;i++)
	{
	
		temp[i]=c%10;
		c=c/10;
		if(c==0)
		{
			break;
		}
	}
	x=i;
	for(i=0;i<=x;i++)
	{
		if(temp[0]==0)
		{
			for(count=0;count<10;count++)
			{
				temp[count]=temp[count+1];
			}
		}
		else
		{
			break;
		}
	}
	b? (temp[0]=temp[0]):(temp[0]=-temp[0]);
	for(i=0;i<=x;i++)
	{
		printf("%d",temp[i]);
	}
} 
