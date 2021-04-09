#include<stdio.h>
int main()
{
    long long a,b;
    int flagab=1;
    while(~scanf("%lld %lld",&a,&b))
    {
        if(a<0&&b>0||a>0&&b<0)
            flagab=-1;
        if(a<0)
			a=-a;
        if(b<0)
			b=-b;
        long long ans=0,tmp=0;
        for(long long i=0;i<b;i++)
        {
            ans=i+1;
            tmp+=b;
            if(tmp>a)
            {
                printf("%d\n",(ans-1)*flagab);
				flagab=1;
                break;
            }
            
        }
    }
}
