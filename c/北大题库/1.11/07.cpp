#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100010],n,m;
bool suc=false;
bool x(int p,int tmp)
{
	int r,l,mid;
	r=n;l=p+1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[mid]==tmp) {
			printf("%d %d",a[p],a[mid]);
			suc=true;
			break;
		}
		else if(a[mid]>tmp)   r=mid-1;
		else	l=mid+1;
		
	}
	return suc;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)    scanf("%d",&a[i]);
	scanf("%d",&m);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
	if(x(i,m-a[i])==true)    break;
	}
	if(suc==false)	printf("No");
}
