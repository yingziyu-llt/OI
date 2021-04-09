#include<stdio.h>
int main()
{
	int in[100],ti[100],tp[100],ta[100],i,temp,p,c,ct=0,x;
	//freopen("count2.in","r",stdin);
	//freopen("count2.out","w",stdout);
	scanf("%d",&x);
	for(i=0;i<x;i++) 
	{
		in[i]=0;
		ti[i]=0;
		ta[i]=0;
		tp[i]=0;
		scanf("%d",&in[i]);	
	}
	for(i=0;i<x;i++)
	{
		
		for(p=0;p<x;p++)
		{
			temp=in[i]+in[p];
			for(c=0;c<x;c++)
			{
				if(temp=ta[c]) break;
				if(temp==in[c])
				{
					ta[ct]=temp;
					ct++;
					break;
				}
			}
		} 
	}
	printf("%d",ct);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
