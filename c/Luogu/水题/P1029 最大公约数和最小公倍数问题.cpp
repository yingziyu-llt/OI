#include<stdio.h>
#include<math.h>
int gcd(int n,int m)
{
	int r=n%m;
	if(r==0)
		return m;
	else
		return gcd(m,r);
}
int main()
{
	int q,p;
	int ans=0;
	scanf("%d%d",&q,&p);
	for(int i=1;i<=sqrt(q*p);i++)
	{
		if((q*p)%i==0&&gcd(i,(q*p)/i)==q) ans++;
	}
	printf("%d",ans*2);
	return 0;
} 
