#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int n,a[10000];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%*d%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int midnum;
	if(n%2==0) midnum=(a[n/2]+a[n/2+1])/2.0;
	else       midnum=a[n/2+1];
	int sum=0; 
	for(int i=1;i<=n;i++)
	 sum+=fabs(a[i]-midnum);
	printf("%d",sum);
	return 0;
} 
