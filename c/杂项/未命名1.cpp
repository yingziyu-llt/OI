#include <stdio.h>
#include <math.h>

int main()
{
    int n2[32],n16[32],n8[32];//n2代表二进制，n16代表16进制，n8代表8进制
	int n,a,b,c,i;//a是暂时储存位，b是当前数位。
    n=a=b=0 ;
	n2[0]=0 ;
    for(b=0;b<=32;b++)
    {
    	n2[b]=0;
    	n8[b]=0;
    	n16[b]=0;
	}
	/*******************************/
	
	printf("写入十进制整数\n");
    scanf("%d",&n);
	/******************************/
	b=0;
    do//2进制 
    {   
        a=n/2;
        n2[31-b]=(n%2);
        n=a;
        b++;
    }
    while(n!=0);
	
		
    i=0;
    while(i!=31)
    {
    	i++;
    	if(n2[i]==0) continue;
    	else break;
	}
	while(i!=31)
    {
    	printf("%d",n2[i]);
    	i++;
    	
    }
	printf("\n");
	/*************************/
	for(b=0;b<=32;b++)
	{
		c=pow(2, b);
		n=n+n2[31-b]*c;
	}
	/***********************/
	b=0;
	do//8进制 
    {   
        a=n/8;
        n8[31-b]=(n%8);
        n=a;
    	b++;			//0(0)5(1)3(2)1(3)2(4)
    }
    while(n!=0);
    
    i=0;
    while(i!=31)
    {
    	i++;
    	if(n8[i]==0) continue;
    	else break;
	}
	
	while(i!=31)
    {
    	printf("%d",n8[i]);
    	i++;
	}
	printf("\n");
	/******************************/ 
	for(b=0;b<=32;b++)
	{
		c=pow(2, b);
		n=n+n2[31-b]*c;
	}
	/**************************/
	for(b=0;b<=32;b++)//16进制 
    {   
        a=n/16;
        n16[b]=(n%16);
        n=a;
    	if(n==0)
        {
            break;
        }
    }
    
    
    
    printf("0x");
    for(b=31;b>=0;b--)
    {
    	if(n16[b]<10)
		{
    	printf("%d",n16[b]);
    	}
    	else
    	{
    		if(n16[b]==10) printf("A");
    		if(n16[b]==11) printf("B");
    		if(n16[b]==12) printf("C");
    		if(n16[b]==13) printf("D");
    		if(n16[b]==14) printf("E");
    		if(n16[b]==15) printf("F");
		}
	}
	printf("\n");
	
	
	
    return 0;
 
}
