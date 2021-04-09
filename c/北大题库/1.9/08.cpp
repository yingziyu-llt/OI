#include<stdio.h>
#include<math.h>
double a[301];
int main()
{
	double max,min,maxk=1,mink=1,ave=0,temp,s=0,maxf=0;
	int i,n;
	scanf("%d",&n);
	scanf("%lf",&a[1]);
	max=a[1];min=a[1];s=a[1];maxk=1;mink=1;
	for(i=2;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		if(a[i]>max)  {max=a[i];maxk=i;}
		if(a[i]<min)  {min=a[i];mink=i;}
		s=s+a[i];
	}
	ave=(s-max-min)/(n-2);
	for(i=1;i<=n;i++)
	{
		temp=fabs(a[i]-ave);
		if(i!=maxk&&i!=mink&&temp>maxf) maxf=temp;
	}
	printf("%.2lf %.2lf",ave,maxf);
	return 0;
} 
