#include<stdio.h>
int main()
{
	int m,n,w,temp,count,c;
	int tm[10],tn[10],least1,lcount;
	scanf("%d",&w);//输入要输入的值 
	count=0;
	least1=w+1; 
	for(m=1;m<=w;m++)
	{
		c=m;
		for(n=1;n<w;n++)
		{
			temp=m+n;
			c=c+temp;//累加 
			if(c==w)
			{
				tm[count]=m;
				tn[count]=n+1;
				if((m+n)<least1)
				{
					least1=m+n;
					lcount=count;
				}
				count++;
				break;
			}
			if(c>w)
			break;
		}
	}
	printf("%d %d",tm[lcount],tn[lcount]);
	return 0;
} 
