#include<stdio.h>
#include<math.h>
int n,k,pie[10000],sum;
double tj[10000]={0};
bool x(double mid)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=tj[i]/mid;
	if(sum>=k+1) return true;
	else return 0;
}
int main()
{
	int i;
	double l,r,mid,ans,max=0;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&pie[i]);
		tj[i]=pie[i]*pie[i]*M_PI;
		if(max<tj[i])  max=tj[i];
	}
	l=0;r=max;
	while(r-l>0.00001)
	{
		
		mid=(l+r)/2;
		if(x(mid))   l=mid;
 		else		  r=mid;
	}
	printf("%.3lf",l);
}
