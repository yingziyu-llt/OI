#include <stdio.h>
long long s,n,p=1000000007;

long long pow(long long a,long long b,long long m)
{
	long long ans=1;
	while(b>0)
	{
      if(b%2==1)
	  {
		ans=ans*a%m;
	  }
		a=a*a%m;
		b>>=1; 
	} 
	return ans;
}
int main()
{
 freopen("magic.in","r",stdin);
 freopen("magic.out","w",stdout);
 scanf("%lld",&n); 
 s=((1-pow(3,n+1,p))/-2)%p; 
 printf("%lld",s);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
