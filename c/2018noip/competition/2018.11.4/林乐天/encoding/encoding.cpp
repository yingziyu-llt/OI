#include<stdio.h>
#include<math.h>
int l,r,mid,n,q;
int main()
{
	freopen("encoding.in","r",stdin);
	freopen("encoding.out","w",stdout);
	scanf("%d %d",&n,&q);
	l = 1;r = n;
	while(r - l > 1)
	{
		mid = (l + r) >> 1;
		if(q > mid)
		{
			q = mid - (q - mid);
			r = mid;
		}
		else
		{
			q = mid + (mid - q);
			l = mid;
		}
	}
	printf("%d",q);
	return 0;
}