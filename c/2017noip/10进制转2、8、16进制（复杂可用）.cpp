#include <stdio.h>
#include <math.h>

int main()
{
    int n2[32],n16[32],n8[32];//n2��������ƣ�n16����16���ƣ�n8����8����
	int n,a,b,c;//a����ʱ����λ��b�ǵ�ǰ��λ��
    n=a=b=0 ;
	n2[0]=0 ;
    for(b=0;b<=32;b++)
    {
    	n2[b]=0;
    	n8[b]=0;
    	n16[b]=0;
	}
	/*******************************/
	
	printf("д��ʮ��������\n");
    scanf("%d",&n);
	
	
    for(b=0;b<=32;b++)//2���� 
    {   
        a=n/2;
        n2[b]=(n%2);
        n=a;
    	if(n==0)
        {
            break;
        }
    }
    for(b=31;b>=0;b--)
    {
    	printf("%d",n2[b]);
	}
	printf("\n");
	/*************************/
	for(b=0;b<=32;b++)
	{
		c=pow(2, b);
		n=n+n2[b]*c;
	}
	/***********************/
	for(b=0;b<=32;b++)//8���� 
    {   
        a=n/8;
        n8[b]=(n%8);
        n=a;
    	if(n==0)
        {
            break;
        }
    }
    for(b=31;b>=0;b--)
    {
    	printf("%d",n8[b]);
	}
	printf("\n");
	 
	for(b=0;b<=32;b++)
	{
		c=pow(2, b);
		n=n+n2[b]*c;
	}

	for(b=0;b<=32;b++)//16���� 
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
 
 
