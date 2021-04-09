#include<stdio.h>
#include<math.h>
double etf=1e-8;
bool x(double a,double b)
{
	if(fabs(a-b)<etf)  return true;
	else               return false;
}
int main()
{
	double len,t,c,d,s,l=0,r=1e12,mid,alpha,rn,tmp;
	scanf("%lf %lf %lf",&len,&t,&c);
	s=(1.0+t*c)*len;
	d=len/2.0;
	if(x(s,len))
	{
		 printf("0.000");
		 return 0;
	}
	while(!x(l,r))
	{
		mid=(l+r)/2.0;
		rn=sqrt((double)(mid*mid+d*d));
		alpha=atan2(d,mid)*2;
		tmp=alpha*rn;
		if(x(tmp,s))
		{
			l=mid;
			break;
		}
		if(tmp-s<0) r=mid;
		else l=mid;
	}
	rn=sqrt(mid*mid+d*d);
	printf("%.3lf",rn-l);
	return 0;
}
