#include<stdio.h>
#include<algorithm>
using namespace std;
int n,k;
long long a[20000];
int main()
{
	long long i,l,r,mid,max=0;
	double tmp;
	long long sum;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lf",&tmp);
		a[i]=(int)(tmp*100);
		if(max<a[i]) max=a[i];
	}
	l=1;r=max;
	sort(a,a+n);
	tmp=0;
	while(l<=r)
	{
		sum=0;
		mid=(l+r)/2;
		for(i=0;i<n;i++)
			sum+=a[i]/mid;
		if(sum<k)       r=mid-1;
		else  {tmp = mid;l=mid+1;}
	}
	printf("%.2lf",tmp/100.0);
	return 0;
}

