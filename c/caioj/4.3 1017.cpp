#include<stdio.h>
int panduan2(int x)
{
    int i,tmp,ans=0,a;
	a=x;
	for(i=0;i<2;i++)
	{
		tmp=a%10;
		a/=10;
		ans=ans*10+tmp;
	}
	return (int)ans==x;
}
int panduan3(int x)
{
    int i,tmp,ans=0,a;
	a=x;
	for(i=0;i<3;i++)
	{
		tmp=a%10;
		a/=10;
		ans=ans*10+tmp;
	}
	return (int)ans==x;
}
int panduan4(int x)
{
    int i,tmp,ans=0,a;
	a=x;
	for(i=0;i<4;i++)
	{
		tmp=a%10;
		a/=10;
		ans=ans*10+tmp;
	}
	return (int)ans==x;
}
int main()
{
    int x,y,i;
    scanf("%d%d",&x,&y);

    for(i=x;i<=y;i++)
    {
           if(i<10)
           {
                  printf("%d\n",i);
           }
           else if(i<100)
           {
                  if( panduan2(i)==1)
                  {
                         printf("%d\n",i);
                  }
            }
            else if(i<1000)
            {
                  if( panduan3(i)==1)
                  {
                         printf("%d\n",i);
                  }
            }
            else
            {
                  if( panduan4(i)==1)
                  {
                        printf("%d\n",i);
                  }
            }
    }

    return 0;
}


