#include<stdio.h>
int time[7][2];
int main()
{
    int i,a,max=-1,maxl;
    for(i=0;i<7;i++)
		scanf("%d %d",&time[i][0],&time[i][1]);
    for(i=0;i<7;i++)
    {
    	a=time[i][0]+time[i][1];
    	if(max<a)
    	{
    		max=a;
    		maxl=i;
    	}
    }
    if(time[maxl][0]+time[maxl][1]<=8)  
    {
    	printf("0");
    	return 0;
    }
    else
    {
    	printf("%d",maxl+1);
    	return 0;
    }
}
