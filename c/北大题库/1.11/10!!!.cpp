#include<stdio.h>
#include<math.h>
int d[50012];
bool y1(int dis,int n,int m)
{
	int last=0,s=0,i;
	for(i=1;i<=n;i++)
	{
		if(d[i]-last>=dis)  last=d[i];
		else s++;
	}
	if(s<=m)    return true;
	else return false;
}
int main()
{
	int i,ln,n,m,l,mid,r,y;
	/***************/
	scanf("%d %d %d",&ln,&n,&m);

	for(i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
	}
	d[i]=ln;
	r=ln;
	l=0;
	/****************/
	while(l+1<r)
	{
		mid=(l+r)/2;
		
		if(y1(mid,n+1,m)) l=mid;
		else    r=mid;
	}
	printf("%d",l);
	return 0;
}
