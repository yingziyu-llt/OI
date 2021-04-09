#include<stdio.h>
#include<math.h>
int n;
int l;
int huzhi(int a,int b)
{
	int i;
	for(i=2;i<l;i++)
	{
		if(a%i==0&&b%i==0)
			return 0;
	}
	return 1;
}
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
	int a,b;
	int x,y;
	double cmp=1000000000;
	scanf("%d%d%d",&a,&b,&l);
	double cc=(double)a/(double)b;
	int i=0,j=0;
	x=a/gcd(a,b);
	y=b/gcd(a,b);
	a/=gcd(a,b);
	b/=gcd(a,b);
	if(x<=l&&y<=l)
	{
		printf("%d %d",x,y);
		return 0;
	}
	for(i=1;i<=l;i++)
	{
		for(j=1;j<=l;j++)
		{
			if((double)i/(double)j>cc&&(double)i/(double)j-cc<cmp-cc&&huzhi(i,j)==1)
			{
				cmp=(double)i/(double)j;
				x=i;
				y=j;	
			}
		}
	}
	printf("%d %d",x,y);
	return 0;
}
