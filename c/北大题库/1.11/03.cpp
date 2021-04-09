#include<stdio.h>
int R,N;
struct aa
{
	int l,t,w,h;
	long s;
}x[10002];
int l,r,mid,y=0,rline;
long long lsum,rsum,z;
long mj(long a)
{
	int i;
	lsum=0;
	rsum=0;
	for(i=1;i<=N;i++)
	{
		if(x[i].l+x[i].w<=a)     lsum+=x[i].s;
		else if(x[i].l>=a)       rsum+=x[i].s;
		else {lsum+=(a-x[i].l)*x[i].h;rsum+=(x[i].l+x[i].w-a)*x[i].h;}
	}
	return rsum-lsum;
}
int main()
{
	int i;
	scanf("%d",&R);
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d %d %d %d",&x[i].l,&x[i].t,&x[i].w,&x[i].h);
		x[i].s=x[i].h*x[i].w;
		if(x[i].l+x[i].w>rline) rline=x[i].l+x[i].w;
	}
	l=0;r=rline;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(mj(mid)<0)   r=mid-1;
		else if(mj(mid)>0)   l=mid+1;
		else if(mj(mid)==0)  break;
	}
	while(mj(mid-1)<=0&&mid-1>=0)
		mid--;
	while(mj(mid)>0&&mid<rline)
		mid++;
	while(mj(mid)==mj(mid+1)&&mid<R)
	{
		mid++;
	}
	printf("%d",mid);
}
