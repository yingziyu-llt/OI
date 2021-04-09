#include<stdio.h>
int m,n,a[100000];
bool s(int x)
{
	int now=0,sum=1;
	for(int i=0;i<n;i++)
	{	if(a[i]>x)  return 0;
		if(now+a[i]<=x)  now+=a[i];
		else    {
			sum++;
			now=a[i];
		}
	}
	if(sum<=m)  return true;
	else return false;
}
int main()
{
	int i,l,r,mid,sum=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
	 	scanf("%d",&a[i]);
		sum+=a[i];
	}
	l=0;r=sum;
	while(l+1<r)
	{
		mid=(l+r)/2;
		bool x=s(mid);
		if(!x)   	l=mid;
		else        r=mid;
	}
	if(s(r))    printf("%d",r);
	else printf("%d",l);
	return 0;
}
